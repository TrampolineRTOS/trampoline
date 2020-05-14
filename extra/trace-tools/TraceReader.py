#! /usr/bin/env python3
# -*- coding: UTF-8 -*-
import json
import sys
import time

class TraceReader:
    ''' Trace reader just… reads a trace!
        This is the master class (interface), herited to get events from
        different sources: serial, gdb, file (json)…
    
        It provides a generator to send events one by one
        In this class, events are considered as 'raw events', as we deal
        only with ids (no names nor external information used).
    '''
    def __init__(self):
        # trace event ids
        self.eventType = ['proc','res','set_event','reset_event','timeobj','timeobj_expire','overflow']

    def getEvent(self):
        ''' Generator that sends raw events one by one to the main thread'''
        pass

    def stop(self):
        ''' need to stop to read events. Called by the main thread'''
        pass

    def readData(self,nb):
        ''' read nb bytes. This method should be defined in subclasses '''
        pass

    def readBinaryEvent(self):
        '''read a binary event. Common method for subclasses (private)'''
        frame = self.readData(5)
        while True:
            #checksum verif
            if len(frame) == 5  and (sum(frame[:4]) & 0xff == frame[4]):
                #ok => get back 4 bytes
                return frame[:4]
            else:
                #nok, read one more byte, and check again
                d = self.readData(1)
                if(len(frame) == 5):
                    frame = frame[1:] + d
                else:
                    frame = frame + d

    #decode the event
    def decodeBinaryEvent(self,evtBin,ts):
        '''decode a binary event. Common method for subclasses (private)'''
        evt = {}
        #time stamp
        curTS = evtBin[1] << 8 | evtBin[2]
        if curTS < (ts & 0xFFFF): #overflow?
            ts += 1<<16
        ts = curTS + (ts  & 0xFFFF0000)
        evt['ts']      = ts
        evt['type']    = self.eventType[evtBin[0] >> 5]
        if evt['type'] == 'proc':
            evt['target_state'] = evtBin[0] & 0x7
            evt['proc_id']  = evtBin[3]
        elif evt['type'] == 'set_event':
            evt['event'] = evtBin[0] & 0x1F
            evt['target_task_id']  = evtBin[3]
        elif evt['type'] == 'reset_event':
            evt['event'] = evtBin[0] & 0x1F
        elif evt['type'] == 'timeobj':
            evt['target_state'] = evtBin[0] & 0x7
            evt['timeobj_id']  = evtBin[3]
        elif evt['type'] == 'timeobj_expire':
            evt['timeobj_id']  = evtBin[3]
        else:
            print('error, not implemented yet: '+evt['type'])
        return (evt,ts)

class TraceReaderFile(TraceReader):
    ''' Get trace events from a JSON file
        We only deal with ids for events here.
    '''
    def __init__(self,inputFileName):
        self.trace = []      #event trace (the one as input/output in JSON format)

        if inputFileName:
            self.readJSONTrace(inputFileName)

    def readJSONTrace(self,filename):
        try:
            with open(filename) as traceFile:
                self.trace = json.load(traceFile)
        except OSError as e:
            print('trace file not found ('+filename+'). '
                  'Maybe, you should run your application first?')
            sys.exit(1)

    def getEvent(self):
        ''' Generator that send raw events one by one'''
        for event in self.trace:
            yield event

class TraceReaderSerial(TraceReader):
    ''' Get trace events from a Serial interface
        We only deal with ids for events here.
    '''
    #def __init__(self,device='/dev/ttyACM1',speed=9600):
    def __init__(self,serialParams,verbose):
        '''
        :param str device: serial device name ('/dev/ttyACM1' for instance on Linux)
        :param int speed : serial speed in bauds
        '''
        import threading, queue
        super().__init__()
        self.verbose = verbose
        #open serial
        try:
            device = serialParams[0]
            speed = int(serialParams[1])
        except (IndexError,ValueError):
            print("Bad serial parameters. The format is 'device,speed'. Speed should be an integer")
            print("example: /dev/ttyACM0,115200")
            sys.exit(1)
        self.ser = self.openSerial(device,speed)
        self.timeStamp = 0  #to take into account overflows (events are in chronological order)
        #thread related to serial reception
        self.evStopSerial = threading.Event() #event to stop the serial reception
        self.serialEventQueue = queue.Queue() #queue between serial thread and main app.
        self.senderThread = threading.Thread(target=self.serialRead)
        self.senderThread.start()

    def openSerial(self,device,speed):
        ser = None
        try:
            import serial
        except ImportError:
            print("The 'serial' python package is not installed");
            print("Please install first the package (Linux, Mac, Win, …)")
            print("here: https://pythonhosted.org/pyserial/index.html")
        try:
            ser = serial.Serial(device, speed, timeout=1)
        except serial.serialutil.SerialException:
            print('Serial line {0} not found'.format(device))
            sys.exit(1)
        return ser

    def serialRead(self):
        ''' reception thread. Reads events on the serial line and put it it the queue'''
        while not self.evStopSerial.is_set():
            #read serial
            evtBin = self.readBinaryEvent()
            (evt,self.timeStamp) = self.decodeBinaryEvent(evtBin,self.timeStamp) 
            self.serialEventQueue.put(evt)
        if self.verbose:
            print('{0} events in the serial queue at the end'.format(self.serialEventQueue.qsize()))
        self.ser.close()

    def getEvent(self):
        ''' Generator that sends raw events one by one from serial. 
            This is executed on the main thread
        '''
        while True:
            event = self.serialEventQueue.get()
            yield event

    def stop(self):
        ''' We need to stop the serial connexion => stop the thread'''
        self.evStopSerial.set()

    def readData(self,nb):
        return self.ser.read(nb)

