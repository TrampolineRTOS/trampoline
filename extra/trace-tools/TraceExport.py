#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

class TraceExport:
    def __init__(self):
        pass

    def timeStamp(self,ev):
        print('[{0: >10}] '.format(ev['ts']), end='')

    """ called by the evaluator when there is 
        a proc change event
    """
    def handleEventProc(self,ev):
        self.timeStamp(ev)
        print('proc {0: <20} change to state {1}'.format(ev['procName'],ev['stateName']))

    """ called by the evaluator when a 
        Time Object expires
    """
    def handleEventTOExpire(self,ev):
        self.timeStamp(ev)
        print('time object expired: {0}'.format(ev['toName']))

    """ called by the evaluator when a 
        Time Object updates
    """
    def handleEventTOUpdate(self,ev):
        self.timeStamp(ev)
        print('time object "{0:>11}" change to state {1}'.format(
               ev['toName'],
               ev['toStateName']))

    """ called by the evaluator when there is a
        Set Event 
    """
    def handleEventSetEvent(self,ev):
        self.timeStamp(ev)
        print('event {0:>12} (id {1}) sent to task {2}'.format(
                ev['evtName'],
                ev['evtMask'],
                ev['procName']))

    """ called by the evaluator when there is a
        Reset Event 
    """
    def handleEventResetEvent(self,ev):
        self.timeStamp(ev)
        print('task {0:>20} resets event {1:>10} (mask {2})'.format(
                ev['procName'],
                ev['evtName'],
                ev['evtMask']))

    """ called by the evaluator when there is an
        overflow 
    """
    def handleEventOverflow(self,ev):
        self.timeStamp(ev)
        print(' ##### OVERFLOW ####')
