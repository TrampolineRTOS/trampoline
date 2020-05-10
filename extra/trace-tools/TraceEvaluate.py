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
        elif rawEvent['type'] == 'timeobj_expire': #alarm expire
            i = int(rawEvent['timeobj_id'])
            to = self.staticInfo.timeObjNames[i]
            event = {'ts':ts, 'id':i, 'toName':to}
            if self.export:
                self.export.handleEventTOExpire(event)
        elif rawEvent['type'] == 'timeobj':   #alarm state update
            i = int(rawEvent['timeobj_id'])
            to = self.staticInfo.timeObjNames[i]
            toState = int(rawEvent['target_state'])
            toStateName = self.staticInfo.timeObjStates[toState]
            event = {'ts':ts, 'id':i, 'toName':to, 'state':toState, 'toStateName':toStateName}
            if self.export:
                self.export.handleEventTOUpdate(event)
        elif rawEvent['type'] == 'set_event': #send event
            target  = int(rawEvent['target_task_id'])
            evtMask = int(rawEvent['event'])
            evtName = self.staticInfo.getEventName(target,evtMask)
            procName  = self.staticInfo.procNames[target]
            event = {'ts':ts, 'proc':target, 'evtMask':evtMask,
                    'procName':procName, 'evtName':evtName}
            if self.export:
                self.export.handleEventSetEvent(event)
        elif rawEvent['type'] == 'reset_event': #reset event
            target  = self.runningTask
            evtMask = int(rawEvent['event'])
            evtName = self.staticInfo.getEventName(target,evtMask)
            procName  = self.staticInfo.procNames[target]
            event = {'ts':ts, 'proc':target, 'evtMask':evtMask,
                    'procName':procName, 'evtName':evtName}
            if self.export:
                self.export.handleEventResetEvent(event)
        elif rawEvent['type'] == 'overflow': #overflow
            event = {'ts':ts}
            if self.export:
                self.export.handleEventOverflow(event)
        else:
            print('unhandled type: {0}'.format(rawEvent['type']))
