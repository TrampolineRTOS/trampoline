#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

import StaticInfo

class TraceEvaluate:
    """ TraceEvaluate merges 'raw events' (aka events from the trace reader, with only ids)
        with the staticInfo (extracted from the goil generated file).
        It adjusts the current running task from events.
    """
    def __init__(self,staticInfo):
        self.staticInfo = staticInfo
        self.runningTask = -1 #unknown task (application may run before, so it's not necessary idle)

    def evaluate(self,rawEvent):
        '''evaluate one raw event, and return event with real names'''
        try:
            ts = rawEvent['ts']
            rawType = rawEvent['type']
            if rawType == 'proc':        #proc state udpdate
                i = int(rawEvent['proc_id'])
                st= int(rawEvent['target_state'])
                procName  = self.staticInfo.procNames[i]
                stateName = self.staticInfo.procStates[st]
                event = {'ts':ts,'type':rawType ,'id':i, 'state':st, 'procName':procName, 'stateName':stateName}
                if stateName=='RUNNING': #//change to running
                    self.runningTask = i
            elif rawType == 'resource': #resources
                i = int(rawEvent['resource_id'])
                st= int(rawEvent['target_state'])
                resourceName  = self.staticInfo.resourceNames[i]
                stateName = self.staticInfo.resourceStates[st]
                procId = self.runningTask
                if procId == -1: #unknown
                    procName  = '<unknown>'
                    #found = True #task unknown => cannot check anything
                else:
                    found = False
                    procName  = self.staticInfo.procNames[procId]
                    tasksAllowed = self.staticInfo.staticInfo['resource'][i]['TASKUSAGE']
                    for task in tasksAllowed:
                        if task['VALUE']==procName:
                            found = True
                    if not found:
                        print('ERROR configuration: the task {0} is not allowed to access resource {1}, at date {2}'.format(procName,resourceName,ts))
                event = {'ts':ts,'type':rawType, 'procName':procName, 'state':st, 'resourceName':resourceName, 'stateName':stateName}
            elif rawType == 'timeobj': #alarm expire
                i = int(rawEvent['timeobj_id'])
                to = self.staticInfo.timeObjNames[i]
                kind = rawEvent['kind']
                evType = rawType+'_'+kind
                if kind == 'expire':
                    event = {'ts':ts,'type':evType, 'id':i, 'toName':to}
                elif kind == 'update_state':
                    toState = int(rawEvent['target_state'])
                    toStateName = self.staticInfo.timeObjStates[toState]
                    event = {'ts':ts,'type':evType, 'id':i, 'toName':to, 'state':toState, 'toStateName':toStateName}
                else:
                    print('ERROR unhandled alarm kind: {0}'.format(rawEvent['kind']))
                    event = {'ts':ts,'type':'trace','info':evType}
            elif rawType == 'event': #events (send/reset)
                evtMask = int(rawEvent['event'])
                kind = rawEvent['kind']
                ok = True
                evType = rawType+'_'+kind
                if kind == 'set': #set event
                    target  = int(rawEvent['target_task_id'])
                    evtName = self.staticInfo.getEventName(target,evtMask)
                    procName  = self.staticInfo.procNames[target]
                    event = {'ts':ts, 'type':evType,'proc':target, 'evtMask':evtMask,
                            'procName':procName, 'evtName':evtName}
                elif kind == 'reset': #reset event
                    target  = self.runningTask
                    if target == -1: #unknown
                        procName = '<unknown>'
                        evtName = '<unknown>'
                    else:
                        evtName = self.staticInfo.getEventName(target,evtMask)
                        procName  = self.staticInfo.procNames[target]
                    event = {'ts':ts, 'type':evType,'proc':target, 'evtMask':evtMask,
                             'procName':procName, 'evtName':evtName}
                else:
                    print('ERROR unhandled event kind: {0}'.format(rawEvent['kind']))
                    event = {'ts':ts,'type':'trace','info':evType}
            elif rawType == 'message': #message
                i = int(rawEvent['msg_id'])
                kind = rawEvent['kind']
                ok = True
                evType = rawType
                if kind[:4] == 'send':
                    msgName = self.staticInfo.msgSendNames[i]
                    evType = rawType+'_'+kind[:4]
                    event = {'ts':ts, 'type':evType, 'id':i, 'msgName':msgName,'kind':kind}
                elif kind == 'receive': #receive message
                    msgName = self.staticInfo.msgRcvNames[i]
                    evType = rawType+'_'+kind
                    event = {'ts':ts, 'type':evType, 'id':i, 'msgName':msgName,'kind':kind}
                else:
                    print('ERROR unhandled message kind: {0}'.format(rawEvent['kind']))
                    event = {'ts':ts,'type':'trace','info':evType}
            elif rawType == 'ioc':
                i = int(rawEvent['ioc_id'])
                iocName = self.staticInfo.iocNames[i]
                evType = rawType+'_'+kind
                event = {'ts':ts, 'type':evType, 'id':i, 'iocName':iocName}     
            elif rawType == 'overflow': #overflow
                event = {'ts':ts,'type':rawType}
            elif rawType == 'trace': #communication pb with trace (serial,…)
                event = {'ts':ts,'type':rawType,'info':'communication'}
            else:
                print('ERROR unhandled type: {0}'.format(rawType))
                event = {'ts':ts,'type':rawType}
            return event
        except IndexError:
            print('ERROR when decoding event: index out of range. Raw event is {0}'.format(rawEvent))
