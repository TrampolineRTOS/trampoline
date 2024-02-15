#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

import re
import sys


#should be updated, depending on the target.
#this main header file should be located in the 'machine/cortex-m/..' part of trampoline
filename = '../../../../../machines/cortex-m/armv7em/stm32h743/CMSIS/Device/ST/STM32H7xx/Include/stm32h743xx.h'
target = 'stm32h743'
#GPIO ports GPIOA, GPIOB, … Required for EXTI interrupt defs
gpios = "ABCDEFGHIJK"

#regexp to find the beginning of the interrupt defs (enum)
startExtractRegExp=re.compile('.*STM32 specific Interrupt Numbers.*$')
# regexp to detect the end (end of enum definition)
stopExtractRegExp=re.compile('.*IRQn_Type.*$')
#regexp to process a line, to get interrupt name, number and description.
#line example:
#   LPTIM2_IRQn                 = 138,    /*!< LP TIM2 global interrupt                                          */
processLineRegExp=re.compile('\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([0-9]+).*!<(.*)\*/.*$')

interruptList = []

#first pass. read file and populate the interruptList data structure.
lineToProcess = False
with open(filename,'r') as stFile:
    for line in stFile:
        if stopExtractRegExp.match(line):
            lineToProcess = False
        if lineToProcess:
            m = processLineRegExp.match(line)
            if m:
                IRQnName = m.groups()[0]
                IRQName = IRQnName[:-1]
                IRQn    = int(m.groups()[1])
                IRQdesc = m.groups()[2].strip()
                interruptList.append((IRQName,IRQn,IRQdesc))
                # print(IRQName + ' => ' + str(IRQn)+ ' : '+ IRQdesc)
                # print('INTERRUPT '+IRQName+' {')
                # print('  VECT = '+str(IRQn+16)+';')
                # print('  SETPRIO = TRUE { NUMBER = '+str(IRQn)+'; };')
                # if not IRQName.find('EXTI'):
                #     print('  ACK = TRUE { ACKTYPE = EXTERNAL; };')
                # print('  VECTOR_TYPE = HANDLER {')
                # print('    NAME = "'+IRQName+'_Handler";')
                # print('  };')
                # print('} : "'+IRQdesc+'";')
                # print()

            else:
                print('** error **')
                print(line)
                sys.exit(1)
        if startExtractRegExp.match(line):
            lineToProcess = True

#second pass: write the .oil file of defs.
with open("interruptDefs.oil",'w') as outFile:
    outFile.write('/*\n')
    outFile.write(' * Interrupt definitions for the '+str(target).upper()+' micro-controller\n')
    outFile.write(' */\n')
    outFile.write('#include "interruptDefsARM.oil"\n\n')
    for IRQName,IRQn,IRQdesc in interruptList:
        outFile.write('INTERRUPT '+IRQName+' {\n')
        outFile.write('  VECT = '+str(IRQn+16)+';\n')
        outFile.write('  SETPRIO = TRUE { NUMBER = '+str(IRQn)+'; };\n')
        if IRQName.find('EXTI') != -1:
            outFile.write('  ACK = TRUE { ACKTYPE = EXTERNAL; };\n')
        outFile.write('  VECTOR_TYPE = HANDLER {\n')
        outFile.write('    NAME = "'+IRQName+'_Handler";\n')
        outFile.write('  };\n')
        outFile.write('} : "'+IRQdesc+'";\n\n')


detectExtiRegExp=re.compile('EXTI([0-9_]+)_IRQ')
#third pass: write the .oil file of interrupt sources.
with open("interruptSources.oil",'w') as outFile:
    outFile.write('/*\n')
    outFile.write(' * Interrupt sources for the '+str(target).upper()+' micro-controller\n')
    outFile.write(' */\n')
    outFile.write('ENUM [\n  SysTick,\n')
    nb = 0
    for IRQName,IRQn,IRQdesc in interruptList:
        nb += 1
        outFile.write('  '+IRQName)
        #special case for EXTI
        m = detectExtiRegExp.match(IRQName)
        if m:
            extiRange = m.groups()[0].split('_')
            outFile.write(' {\n')
            if len(extiRange) == 1: #only one exti. Easy
                outFile.write('    ENUM [\n')
                for gpio in gpios:
                    outFile.write('      P'+gpio+extiRange[0]+' { #include <sensibility.oil> }')
                    if gpio != gpios[-1]:
                        outFile.write(',')
                    outFile.write('\n')
                outFile.write('    ] PIN;\n')
            elif len(extiRange) == 2: #exti sources are shared, e.g. EXTI9_5
                startExti = int(extiRange[1])
                endExti = int(extiRange[0])
                for id in range(startExti, endExti+1):
                    outFile.write('    ENUM [\n')
                    for gpio in gpios:
                        outFile.write('      P'+gpio+str(id)+' { #include <sensibility.oil> },\n')
                    outFile.write('      NONE\n')
                    outFile.write('    ] PINON'+str(id)+' = NONE;\n')
            outFile.write('  }')
        #special case for UART/USART,LPUART
        if IRQName.find('USART') != -1 or IRQName.find('UART') != -1:
            outFile.write('  {\n')
            outFile.write('    ENUM [ TXE, CTS, TC, RXNE, ORE, IDLE, PE, LBD, NF, FE ] EVFLAG[];\n')
            outFile.write('  }')
        #epilogue
        if nb != len(interruptList):
            outFile.write(',')    
        outFile.write('\n')
    outFile.write('] SOURCE;\n\n')
