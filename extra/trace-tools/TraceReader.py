#! /usr/bin/env python3
# -*- coding: UTF-8 -*-
import json
import sys

""" Trace reader just… reads a trace!
    It get the trace from the the device (serial, gdb, …) or directly
    from a saved json file.
    Then, it provides a generator to send events one by one
    In this class, events are considered as 'raw events', as we deal
    only with ids (no names nor external information used).
"""
class TraceReader:
    def __init__(self,inputFileName):
        self.trace = []      #event trace (the one as input/output in JSON format)

        if inputFileName:
            self.readJSONTrace(inputFileName)

    """ first simple reader. We get directly the trace
    """
    def readJSONTrace(self,filename):
        try:
            with open(filename) as traceFile:
                self.trace = json.load(traceFile)
        except OSError as e:
            print('trace file not found ('+filename+'). '
                  'Maybe, you should run your application first?')
            sys.exit(1)

    """ Generator that send raw events one by one
    """
    def getEvent(self):
        for event in self.trace:
            yield event
