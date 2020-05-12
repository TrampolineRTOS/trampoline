#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

class TraceExport:
    def __init__(self):
        pass

    def handleEventProc(self,ev):
        ''' called by the evaluator when there is a proc change event.'''
        pass

    def handleEventTOExpire(self,ev):
        ''' called by the evaluator when a Time Object expires.'''
        pass

    def handleEventTOUpdate(self,ev):
        ''' called by the evaluator when a Time Object updates.'''
        pass

    def handleEventSetEvent(self,ev):
        ''' called by the evaluator when there is a Set Event.'''
        pass

    def handleEventResetEvent(self,ev):
        ''' called by the evaluator when there is a Reset Event.'''
        pass

    def handleEventOverflow(self,ev):
        ''' called by the evaluator when there is an overflow (i.e. communication is too slow)'''
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

    def handleEventTOExpire(self,ev):
        ''' called by the evaluator when a Time Object expires.'''
        self.timeStamp(ev)
        print('time object expired: {0}'.format(ev['toName']))

    def handleEventTOUpdate(self,ev):
        ''' called by the evaluator when a Time Object updates.'''
        self.timeStamp(ev)
        print('time object "{0:>11}" change to state {1}'.format(
               ev['toName'],
               ev['toStateName']))

    def handleEventSetEvent(self,ev):
        ''' called by the evaluator when there is a Set Event.'''
        self.timeStamp(ev)
        print('event {0:>12} (id {1}) sent to task {2}'.format(
                ev['evtName'],
                ev['evtMask'],
                ev['procName']))

    def handleEventResetEvent(self,ev):
        ''' called by the evaluator when there is a Reset Event.'''
        self.timeStamp(ev)
        print('task {0:>20} resets event {1:>10} (mask {2})'.format(
                ev['procName'],
                ev['evtName'],
                ev['evtMask']))

    def handleEventOverflow(self,ev):
        ''' called by the evaluator when there is an overflow (i.e. communication is too slow)'''
        self.timeStamp(ev)
        print(' ##### OVERFLOW ####')
