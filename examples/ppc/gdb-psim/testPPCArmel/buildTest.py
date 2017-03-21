#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os;
import re;
import sys;
import subprocess;


services = [
    {'name': 'ActivateTask'   ,'args': '(iamsolonely)'},
    {'name': 'ChainTask'      ,'args': '(iamsolonely)'},
    {'name': 'GetResource'    ,'args': '(res)'},
    {'name': 'GetTaskID'      ,'args': '(iamsolonely)'},
    {'name': 'ReleaseResource','args': '(res)'},
    {'name': 'Schedule'       ,'args': '()'},
    {'name': 'TerminateTask'  ,'args': '()'}
]

def updateSrcFile(key):
    source = open("lonely.c.base", "r")
    dest   = open("lonely.c", "w")
    for ligne in source:
        #look for __KEY__
        m = re.search(b'(.*)__KEY__(.*)',ligne)
        if m != None:
            #ok
            dest.write(m.group(1)+key+m.group(2)+'\n')
        else:
            #nok => std line.
            dest.write(ligne)
    source.close()
    dest.close()

if __name__ == '__main__':
    for service in services:
        #update source file
        updateSrcFile(service['name']+service['args'])
        #goil
        goil = '../../../../goil/makefile-macosx/goil'
	if subprocess.call([goil,'--target=ppc/psim','--templates=../../../../goil/templates/','lonely.oil']):
            sys.exit(1)
        #make
	if subprocess.call(['./make.py']):
            sys.exit(2)
        #rename
        os.rename('./lonely_exe', './test'+service['name']+'.elf')
