#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

class TraceExport:
    def __init__(self):
        pass

    def handleEventProc(self,ev):
        ''' called by the evaluator when there is a proc change event.'''
        pass

    def handleEventResource(self,ev):
        ''' called by the evaluator when a resource is taken/free event.'''
        pass

    def handleEventTO(self,ev):
        ''' called by the evaluator when a Time Object is updated.'''
        pass

    def handleEventEvent(self,ev):
        ''' called by the evaluator when there is a Set/Reset Event.'''
        pass

    def handleEventOverflow(self,ev):
        ''' called by the evaluator when there is an overflow (i.e. communication is too slow)'''
        pass

    def handleEventTrace(self,ev):
        ''' called by the evaluator a pb is detected when retrieving the trace (bad checksum)'''
        pass

    def handleEventMessage(self,ev):
        ''' called by the evaluator when a message is sent/received.'''
        pass

class TraceExportTxt(TraceExport):
    def __init__(self):
        pass

    def timeStamp(self,ev):
        print('[{0: >10}] '.format(ev['ts']), end='')

    def handleEventProc(self,ev):
        ''' called by the evaluator when there is a proc change event.'''
        self.timeStamp(ev)
        print('proc {0: <20} change to state {1}'.format(ev['procName'],ev['stateName']))

    def handleEventResource(self,ev):
        ''' called by the evaluator when a resource is taken/free event.'''
        self.timeStamp(ev)
        print('proc {0: <20} change resource {1} to state {2}'.format(ev['procName'],ev['resourceName'],ev['stateName']))

    def handleEventTO(self,ev):
        ''' called by the evaluator when a Time Object is updated.'''
        self.timeStamp(ev)
        if ev['kind'] == 'expire':
            print('time object expired: {0}'.format(ev['toName']))
        elif ev['kind'] == 'update_state':
            print('time object "{0:>11}" change to state {1}'.format(
               ev['toName'],
               ev['toStateName']))
        else:
            print('ERROR in Trace Export. Unknown time object kind {1}'.format(ev['kind']))

    def handleEventEvent(self,ev):
        ''' called by the evaluator when there is a Set/Reset Event.'''
        self.timeStamp(ev)
        if ev['kind'] == 0: #set
            print('event {0:>12} (id {1}) sent to task {2}'.format(
                    ev['evtName'],
                    ev['evtMask'],
                    ev['procName']))
        else: #reset
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

    def handleEventMessage(self,ev):
        ''' called by the evaluator when a zero message is sent.'''
        self.timeStamp(ev)
        kind = ev['kind']
        if kind == 'send_zero':
            print('zero message sent: {0}'.format(ev['msgName']))
        elif kind == 'send':
            print('message sent: {0}'.format(ev['msgName']))
        elif kind == 'receive':
            print('msg  received: {0}'.format(ev['msgName']))
        else:
            print('ERROR in Trace Export. Unknown message kind {1}'.format(ev['kind']))

    def handleEventOverflow(self,ev):
        ''' called by the evaluator when there is an overflow (i.e. communication is too slow)'''
        print('*** ERROR, OVERFLOW : some messages may have been deleted ***')
    def handleEventTrace(self,ev):
        ''' called by the evaluator a pb is detected when retrieving the trace (bad checksum)'''
        print('*** ERROR, TRACE CHECKSUM : some messages may have been deleted ***')
