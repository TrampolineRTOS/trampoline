#! /usr/bin/env python
# -*- coding: UTF-8 -*-
from __future__ import print_function
from math import *

# This simple python script computes baud-rate settings
# for different input frequencies

# The algorithm is extracted from the user's guide
# (slau367o.pdf), p.776
# the 2 tabulars fracFreq and ucbrsTab are extracted from 
# table 30-4 of this user's guide
# tabular DCOfreq gives the frequencies of the DCO from
# its configuration (dcofsel[3..1] | dcorsel).
# the algorithm is the one in "Baud-rate settings quick set up"


fracFreq = [
	0.0000, 0.0529, 0.0715, 0.0835,
	0.1001, 0.1252, 0.1430, 0.1670,
	0.2147, 0.2224, 0.2503, 0.3000,
	0.3335, 0.3575, 0.3753, 0.4003,
	0.4286, 0.4378, 0.5002, 0.5715,
	0.6003, 0.6254, 0.6432, 0.6667,
	0.7001, 0.7147, 0.7503, 0.7861,
	0.8004, 0.8333, 0.8464, 0.8572,
	0.8751, 0.9004, 0.9170, 0.9288]

ucbrsTab = [
	0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x11,
	0x21, 0x22, 0x44, 0x25, 0x49, 0x4A, 0x52, 0x92,
	0x53, 0x55, 0xAB, 0x6B, 0xAD, 0xB5, 0xB6, 0xD6,
	0xB7, 0xBB, 0xDD, 0xED, 0xEE, 0xBF, 0xDF, 0xEF,
	0xF7, 0xFB, 0xFD, 0xFE]


DCOfreq = [1000000, 1000000,2670000, 5330000,
           3500000, 7000000,4000000, 8000000,
           5330000,16000000,7000000,21000000,
           8000000,24000000,      0,       0]

def exportTab(valList,name):
    print('const uint16_t '+name+'[] = {',end='')
    i = 0;
    for val in valList:
        if i != 0:
            print(', ',end='')
        if i%8 == 0:
            print('\n\t',end='')
        print(hex(val),end='')
        i = i+1
    print('};')

uartFreq = 9600
brw   = [] 
mctlw = [] 
for freq in DCOfreq:
    ucbr   = 0
    ucos16 = 0
    ucbrf  = 0
    ucbrs  = 0
    if freq != 0:
        N = (float)(freq)/uartFreq
        if N > 16:
            ucos16 = 1
            ucbr = (int)(N/16)
            ucbrf = (int)(((N/16)-floor(N/16))*16)
        else:
            ucbr = (int)(N)
        frac = N-floor(N);
        i = 1
        while frac > fracFreq[i]:
            i = i+1
        i = i-1
        ucbrs = ucbrsTab[i]
    #regs
    brw.append(ucbr)
    mctlw.append(ucbrs << 8 | ucbrf << 4 | ucos16)

exportTab(brw,   'tpl_brwTab')
exportTab(mctlw, 'tpl_mctlwTab')
