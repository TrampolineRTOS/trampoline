#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

import StaticInfo

class TraceEvaluate:
    """ TraceEvaluate merges 'raw events' (aka events from the trace reader, with only ids)
        with the staticInfo (extracted from the goil generated file).
        It adjusts the current running task from events.
        If there is an export object (TraceExport), it will call dedicated functions
        to generate reports (text based or gui).
    """
    def __init__(self,staticInfo):
        self.staticInfo = staticInfo
        self.runningTask = staticInfo.getIdleTaskId()
        self.export = None

    def setExport(self,export):
        self.export = export

    def evaluate(self,rawEvent):
        '''evaluate one raw event. Main function'''
        try:
            ts = rawEvent['ts']
            if rawEvent['type'] == 'proc':        #proc state udpdate
                i = int(rawEvent['proc_id'])
                st= int(rawEvent['target_state'])
                procName  = self.staticInfo.procNames[i]
                stateName = self.staticInfo.procStates[st]
                event = {'ts':ts, 'id':i, 'state':st, 'procName':procName, 'stateName':stateName}
                if self.export:
                    self.export.handleEventProc(event)
                if stateName=='RUNNING': #//change to running
                    self.runningTask = i
            elif rawEvent['type'] == 'resource': #resources
                i = int(rawEvent['resource_id'])
                st= int(rawEvent['target_state'])
                procId = self.runningTask
                procName  = self.staticInfo.procNames[procId]
                resourceName  = self.staticInfo.resourceNames[i]
                stateName = self.staticInfo.resourceStates[st]
                found = False
                tasksAllowed = self.staticInfo.staticInfo['resource'][i]['TASKUSAGE']
                for task in tasksAllowed:
                    if task['VALUE']==procName:
                        found = True
                if not found:
                    print('ERROR configuration: the task {0} is not allowed to access resource {1}'.format(procName,resourceName))
                event = {'ts':ts, 'procName':procName, 'state':st, 'resourceName':resourceName, 'stateName':stateName}
                if self.export:
                    self.export.handleEventResource(event)
            elif rawEvent['type'] == 'timeobj': #alarm expire
                i = int(rawEvent['timeobj_id'])
                to = self.staticInfo.timeObjNames[i]
                kind = rawEvent['kind']
                if kind == 'expire':
                    event = {'ts':ts, 'id':i, 'toName':to,'kind':kind}
                    if self.export:
                        self.export.handleEventTO(event)
                elif kind == 'update_state':
                    toState = int(rawEvent['target_state'])
                    toStateName = self.staticInfo.timeObjStates[toState]
                    event = {'ts':ts, 'id':i, 'toName':to, 'state':toState, 'toStateName':toStateName,'kind':kind}
                    if self.export:
                        self.export.handleEventTO(event)
                else:
                    print('ERROR unhandled alarm kind: {0}'.format(rawEvent['kind']))
            elif rawEvent['type'] == 'event': #events (send/reset)
                evtMask = int(rawEvent['event'])
                kind = rawEvent['kind']
                ok = True
                if kind == 'set': #set event
                    target  = int(rawEvent['target_task_id'])
                    evtName = self.staticInfo.getEventName(target,evtMask)
                    procName  = self.staticInfo.procNames[target]
                    event = {'ts':ts, 'proc':target, 'evtMask':evtMask,
                            'procName':procName, 'evtName':evtName, 'kind':kind}
                elif kind == 'reset': #reset event
                    target  = self.runningTask
                    evtName = self.staticInfo.getEventName(target,evtMask)
                    procName  = self.staticInfo.procNames[target]
                    event = {'ts':ts, 'proc':target, 'evtMask':evtMask,
                            'procName':procName, 'evtName':evtName, 'kind':kind}
                else:
                    print('ERROR unhandled event kind: {0}'.format(rawEvent['kind']))
                    ok = False
                if ok:
                    if self.export:
                        self.export.handleEventEvent(event)
            elif rawEvent['type'] == 'message': #message
                i = int(rawEvent['msg_id'])
                kind = rawEvent['kind']
                ok = True
                if kind[:4] == 'send':
                    msgName = self.staticInfo.msgSendNames[i]
                elif kind == 'receive': #receive message
                    msgName = self.staticInfo.msgRcvNames[i]
                else:
                    print('ERROR unhandled message kind: {0}'.format(rawEvent['kind']))
                    ok = False
                if ok:
                    event = {'ts':ts, 'id':i, 'msgName':msgName,'kind':kind}
                    if self.export:
                        self.export.handleEventMessage(event)   
            elif rawEvent['type'] == 'ioc':
                i = int(rawEvent['ioc_id'])
                iocName = self.staticInfo.iocNames[i]
                event = {'ts':ts, 'id':i, 'iocName':iocName}     
                if rawEvent['kind'] == 'send': #send ioc
                    if self.export:
                        self.export.handleEventSendIoc(event)
                elif rawEvent['kind'] == 'receive': #receive ioc
                    if self.export:
                        self.export.handleEventReceiveIoc(event)   
                else:
                    print('ERROR unhandled ioc kind: {0}'.format(rawEvent['kind']))
            elif rawEvent['type'] == 'overflow': #overflow
                event = {'ts':ts}
                if self.export:
                    self.export.handleEventOverflow(event)
            elif rawEvent['type'] == 'trace': #communication pb with trace (serial,…)
                event = {'ts':ts}
                if self.export:
                    self.export.handleEventTrace(event)
            else:
                print('ERROR unhandled type: {0}'.format(rawEvent['type']))
        except IndexError:
            print('ERROR when decoding event: index out of range. Raw event is {0}'.format(rawEvent))
