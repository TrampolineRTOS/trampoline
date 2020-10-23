#! /usr/bin/env python3
# -*- coding: UTF-8 -*-
import json
import sys

#---------------------------------
#read static information JSON file
#---------------------------------
class StaticInfo:
    '''This class reads static information json file. The static information is produced by goil (tpl_static_info.json). This files helps to make the link between the ids (integers) and the name  of Trampoline objects (alarms, tasks, events, resources, …)
    '''
    def __init__(self,filename):
        self.staticInfo    = [] #JSON raw data

        self.procNames     = [] #procs names (including idle)
        self.timeObjNames  = [] #alarms names

        self.procStates    = [] #tasks  states (trampoline specific)
        self.timeObjStates = [] #alarms states (trampoline specific)
        self.readJSON(filename)

    #convert event mask to index.
    def getEventName(self,task,mask):
        for taskEvt in self.staticInfo['task'][task]['EVENT']:
            for evt in self.staticInfo['event']:
                if evt['MASK'] == mask and taskEvt['VALUE'] == evt['NAME']:
                    return evt['NAME']

    def readJSON(self,filename):
        try:
            with open(filename) as staticInfoFile:
                self.staticInfo = json.load(staticInfoFile)
        except OSError as e:
            print('static information file not found ('+filename+'). '
                  'You should enable the trace in the .oil file and '
                  'recompile your application.')
            sys.exit(1)
        # proc (task+isr) names
        for proc in self.staticInfo['task']:
            self.procNames.append(proc['NAME'])
        for proc in self.staticInfo['isr']:
            self.procNames.append(proc['NAME'])
        self.procNames.append('idle') #idle task is the last one.
        #time objs
        for to in self.staticInfo['alarm']:
            self.timeObjNames.append(to['NAME'])
        # OS constant names (task states, alarm states)
        self.procStates = ['SUSPENDED','READY','RUNNING','WAITING','AUTOSTART','READY_AND_NEW']
        self.timeObjStates = ['SUSPENDED','READY','RUNNING','WAITING','AUTOSTART','READY_AND_NEW']

    def getIdleTaskId(self):
        #idle task is the last one.
        return len(self.procNames)-1

    def debug(self):
        ''' print basic debugging info '''
        #procs
        print('Tasks  ('+str(len(self.procNames))+'):')
        for proc in self.procNames:
            print('\t'+proc)
        #alarms
        print('Alarms ('+str(len(self.timeObjNames))+'):')
        for al in self.timeObjNames:
            print('\t'+al)

if __name__ == "__main__":
    filename = 'tpl_static_info.json'
    if len(sys.argv) == 2:
        filename = sys.argv[1]
    si = StaticInfo(filename)
    si.debug()

