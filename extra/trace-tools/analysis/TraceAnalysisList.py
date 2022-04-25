#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

import TraceAnalysis
class TraceAnalysisList(TraceAnalysis.TraceAnalysis):

    ''' main entry point dispatch event in each function '''
    def handleEvent(self,ev):
        self.handlers[ev['type']](ev)

    def timeStamp(self,ev):
        print('[{0: >10}] '.format(ev['ts']), end='')

    def __init__(self,si):
        self.handlers = {
                'proc': self.handleEventProc, 
                'resource':self.handleEventResource,
                'timeobj_expire':self.handleEventtimeobj_expire,
                'timeobj_update_state':self.handleEventtimeobj_update_state,
                'event_set':self.handleEventEvent_set,
                'event_reset':self.handleEventEvent_reset, 
                'message_send':self.handleEventMessageSend,
                'message_receive':self.handleEventMessageReceive,
                'ioc_send':self.handleEventSendIoc, 
                'ioc_receive': self.handleEventReceiveIoc, 
                'overflow': self.handleEventOverflow, 
                'trace': self.handleEventTrace}

    def handleEventProc(self,ev):
        ''' called by the evaluator when there is a proc change event.'''
        self.timeStamp(ev)
        print('proc {0: <20} change to state {1}'.format(ev['procName'],ev['stateName']))

    def handleEventResource(self,ev):
        ''' called by the evaluator when a resource is taken/free event.'''
        self.timeStamp(ev)
        print('proc {0: <20} change resource {1} to state {2}'.format(ev['procName'],ev['resourceName'],ev['stateName']))

    def handleEventtimeobj_expire(self,ev):
        ''' called by the evaluator when a Time Object expires.'''
        self.timeStamp(ev)
        print('time object expired: {0}'.format(ev['toName']))

    def handleEventtimeobj_update_state(self,ev):
        ''' called by the evaluator when a Time Object is updated.'''
        self.timeStamp(ev)
        print('time object "{0:>11}" change to state {1}'.format(
               ev['toName'],
               ev['toStateName']))

    def handleEventEvent_set(self,ev):
        ''' called by the evaluator when there is a Set Event.'''
        self.timeStamp(ev)
        print('event {0:>12} (id {1}) sent to task {2}'.format(
                ev['evtName'],
                ev['evtMask'],
                ev['procName']))

    def handleEventEvent_reset(self,ev):
        ''' called by the evaluator when there is a Reset Event.'''
        self.timeStamp(ev)
        print('task {0:>20} resets event {1:>10} (mask {2})'.format(
                ev['procName'],
                ev['evtName'],
                ev['evtMask']))

    def handleEventSendIoc(self,ev):
        ''' called by the evaluator when an ioc message is sent.'''
        self.timeStamp(ev)
        print('ioc  sent: {0}'.format(ev['iocName']))

    def handleEventReceiveIoc(self,ev):
        ''' called by the evaluator when an ioc message is received.'''
        self.timeStamp(ev)
        print('ioc  received: {0}'.format(ev['iocName']))

    def handleEventMessageSend(self,ev):
        ''' called by the evaluator when a message is sent.'''
        self.timeStamp(ev)
        kind = ev['kind']
        if kind == 'send_zero':
            print('zero message sent: {0}'.format(ev['msgName']))
        elif kind == 'send':
            print('message sent: {0}'.format(ev['msgName']))
        else:
            print('ERROR in Trace Export. Unknown message kind {1}'.format(ev['kind']))
    def handleEventMessageReceive(self,ev):
        ''' called by the evaluator when a zero message is sent.'''
        self.timeStamp(ev)
        kind = ev['kind']
        print('msg  received: {0}'.format(ev['msgName']))

    def handleEventOverflow(self,ev):
        ''' called by the evaluator when there is an overflow (i.e. communication is too slow)'''
        print('*** ERROR, OVERFLOW : some messages may have been deleted ***')

    def handleEventTrace(self,ev):
        ''' called by the evaluator a pb is detected when retrieving the trace (bad checksum)'''
        print('*** ERROR, TRACE CHECKSUM : some messages may have been deleted ***')
