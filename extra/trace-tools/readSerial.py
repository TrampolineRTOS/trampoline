#! /usr/bin/env python3
# -*- coding: UTF-8 -*-
import json
import sys

try:
    import serial
except ImportError:
    print("The 'serial' python package is not installed");
    print("Please install first the package (Linux, Mac, Win, …)")
    print("here: https://pythonhosted.org/pyserial/index.html")

# trace event ids
eventType = ['proc','res','set_event','reset_event','timeobj','timeobj_expire']

#read a binary event on serial line
def readEvent(ser):
    frame = ser.read(5)
    offset = 0
    while True:
        #checksum verif
        if sum(frame[offset:offset+4]) & 0xff == frame[-1]:
            #ok => get back 4 bytes
            return frame[offset:offset+4]
        else:
            #nok, read one more byte, and check again
            ser.read(1)
            offset = offset + 1

#decode the event
def decodeEvent(evtBin,ts):
    evt = {}
    #time stamp
    curTS = evtBin[1] << 8 | evtBin[2]
    if curTS < (ts & 0xFFFF): #overflow?
        ts += 1<<16
    ts = curTS + (ts  & 0xFFFF0000)
    evt['ts']      = ts
    evt['type']    = eventType[evtBin[0] >> 5]
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

#---------------------------------
#Ok, now serial line.
#---------------------------------
serialLine = '/dev/ttyACM1'
try:
    ser = serial.Serial(serialLine, 9600, timeout=1)
except serial.serialutil.SerialException:
    print('Serial line {0} not found'.format(serialLine))
    sys.exit(1)

evtList = []
ts=0 #timestamp
while len(evtList) < 5000:
    evtBin = readEvent(ser)
    (evt,ts) = decodeEvent(evtBin,ts) 
    evtList.append(evt)
    if (len(evtList) % 50) == 0:
        print('*', end='')
    sys.stdout.flush()

ser.close()
with open("trace.json", "w") as outfile:
    json.dump(evtList, outfile, indent=2)

