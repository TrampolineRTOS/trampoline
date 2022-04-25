#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

import TraceAnalysis
class TraceAnalysisCpuLoad(TraceAnalysis.TraceAnalysis):
    def __init__(self,si):
        self.si = si
        nbProc = len(si.procNames)
        self.cpuTime  = [0]*nbProc #cumulative running time
        self.taskIsRunning = [False]*nbProc #boolean map of running tasks
        self.startDate = 0 #store the date when the proc starts execution 
        self.startRecord = -1 #first time stamp
        self.endRecord = 0   #last time stam

    def handleEvent(self,event):
        if event['type'] == 'proc':
            currentProcId = event['id']
            if event['stateName'] == 'RUNNING':
                self.taskIsRunning[currentProcId] = True
                self.startDate = event['ts']
                #print('** task '+str(currentProcId)+' run => '+str(self.startDate))
                if self.startRecord < 0:
                    self.startRecord = self.startDate
            else: #not running state
                if self.taskIsRunning[currentProcId]: #but before yes => stop
                    endDate = event['ts']
                    #print('** task '+str(currentProcId)+' stop => '+str(endDate))
                    #cumulate previous
                    duration = endDate - self.startDate
                    self.cpuTime[currentProcId] += duration
                    #if duration > 0:
                    #    print('## task '+str(currentProcId)+' duration => '+str(duration))
                    self.endRecord = endDate
                #else:
                #    print('task '+str(currentProcId)+' '+event['stateName']+' => '+str(event['ts']))
                self.taskIsRunning[currentProcId] = False

    def stop(self):
        index = 0
        recordTime = self.endRecord - self.startRecord
        print('start {0} '.format(self.startRecord))
        print('end   {0} '.format(self.endRecord))
        print('trace duration {0} '.format(recordTime))
        for duration in self.cpuTime:
            print('proc {0: <20} : {1:6.2%} ({2})'.format(self.si.procNames[index],duration/recordTime,duration))
            index += 1


