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
        self.eventType = ['overflow','proc','resource','event','timeobj','message','ioc']

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
        gotPb = False
        while True:
            #checksum verif
            if len(frame) == 5  and (sum(frame[:4]) & 0xff == frame[4]):
                #ok => get back 4 bytes
                return (gotPb,frame[:4])
            else:
                #nok, read one more byte, and check again
                d = self.readData(1)
                if(len(frame) == 5):
                    f= ':'.join('{:02x}'.format(i) for i in frame) #debug
                    print('ERROR: Serial read problem. Frame is '+f)
                    gotPb = True
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
        evt['bin'] = ':'.join('{:02x}'.format(i) for i in evtBin) #debug
        if evt['type'] == 'proc':
            evt['target_state'] = evtBin[0] & 0x7
            evt['proc_id']  = evtBin[3]
        elif evt['type'] == 'resource':
            evt['target_state'] = evtBin[0] & 0x1
            evt['resource_id']  = evtBin[3]
        elif evt['type'] == 'event':
            kind = (evtBin[3]>>7)&1 #0 set, 1 reset
            evt['event'] = evtBin[0] & 0x1F
            if (kind == 0 ) :   # change state
                evt['kind'] = 'set'
                evt['target_task_id']  = evtBin[3] & 0x7F
            else:
                evt['kind'] = 'reset'
                if evtBin[3] & 0x7F != 0:
                    print('ERROR : invalid reset event, got a target task')
        elif evt['type'] == 'timeobj':
            evt['timeobj_id']  = evtBin[3]
            kind = (evtBin[0]>>4)&1 #0 change state, 1 expire
            if (kind == 0 ) :   # change state
                evt['kind'] = 'update_state'
                evt['target_state'] = evtBin[0] & 0x7
            elif (kind == 1 ) : # SEND_ZERO_MESSAGE
                evt['kind'] = 'expire'
                if (evtBin[0] & 0x07) != 0:
                    print('ERROR invalid time object event, got a time object state, but time object expires.')
        elif evt['type'] == 'message':
            evt['msg_id'] = evtBin[0] & 0x1F
            kind = evtBin[3]
            if (kind == 0 ) :   # SEND_NONZERO_MESSAGE
                evt['kind'] = 'send'
            elif (kind == 1 ) : # SEND_ZERO_MESSAGE
                evt['kind'] = 'send_zero'
            elif (kind == 2 ) : # MESSAGE_RECEIVE
                evt['kind'] = 'receive'
            else :
                print('ERROR, invalid message type: '+str(evtBin[3]))
        elif evt['type'] == 'overflow':
            pass
        else:
            print('ERROR, not implemented yet: '+evt['type'])
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
            #we flush the input buffer.
            # https://stackoverflow.com/questions/7266558/pyserial-buffer-wont-flush
            time.sleep(0.2)
            ser.reset_input_buffer()
        except serial.serialutil.SerialException:
            print('Serial line {0} not found'.format(device))
            sys.exit(1)
        return ser

    def serialRead(self):
        ''' reception thread. Reads events on the serial line and put it it the queue'''
        firstReception = True
        while not self.evStopSerial.is_set():
            #read serial
            (gotPb, evtBin) = self.readBinaryEvent()
            (evt,self.timeStamp) = self.decodeBinaryEvent(evtBin,self.timeStamp) 
            #we tolerate a bad serial reception at begining (synchro)
            if gotPb and not firstReception:
                evtPb = {}
                evtPb['ts'] = evt['ts']
                evt['bin'] = ':'.join('{:02x}'.format(i) for i in evtBin) #debug
                evtPb['type'] = 'trace'
                self.serialEventQueue.put(evtPb)
            self.serialEventQueue.put(evt)
            firstReception = False
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
        data = self.ser.read(nb)
        return data

class TraceReaderDump(TraceReader):
    ''' Get trace events from a file dump (binary file)
        not well tested, for debug.
    '''
    def __init__(self,filename,verbose):
        '''
        :param str device: serial device name ('/dev/ttyACM1' for instance on Linux)
        :param int speed : serial speed in bauds
        '''
        import threading, queue
        super().__init__()
        self.verbose = verbose
        self.data = []
        #open serial
        self.infile=open(filename,'rb')
        self.timeStamp = 0  #to take into account overflows (events are in chronological order)
        #thread related to serial reception
        self.evStopSerial = threading.Event() #event to stop the serial reception
        self.serialEventQueue = queue.Queue() #queue between serial thread and main app.
        self.senderThread = threading.Thread(target=self.dumpRead)
        self.senderThread.start()

    def dumpRead(self):
        ''' reception thread. Reads events on the serial line and put it it the queue'''
        firstReception = True
        while not self.evStopSerial.is_set():
            #read serial
            (gotPb, evtBin) = self.readBinaryEvent()
            (evt,self.timeStamp) = self.decodeBinaryEvent(evtBin,self.timeStamp) 
            #we tolerate a bad serial reception at begining (synchro)
            if gotPb and not firstReception:
                evtPb = {}
                evtPb['ts'] = evt['ts']
                evt['bin'] = ':'.join('{:02x}'.format(i) for i in evtBin) #debug
                evtPb['type'] = 'trace'
                self.serialEventQueue.put(evtPb)
            self.serialEventQueue.put(evt)
            firstReception = False
        if self.verbose:
            print('{0} events in the serial queue at the end'.format(self.serialEventQueue.qsize()))
        self.infile.close()

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
        return self.infile.read(nb)
