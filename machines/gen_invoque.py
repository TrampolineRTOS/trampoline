#!/usr/bin/python
##
# @file gen_invoque.py
#
# @section descr File description
#
# gen_invoque.py generates the tpl_invoque.s file that contains
# the API function in assembly language using a system call to
# switch to the kernel. gen_invoque.py uses a template file called
# invoque.tpl that should be located in the machine/$ARCH directory
# This template file is the assembly instruction code snippet with
# the placeholder for the system call name being $SYSCALLNAME$
# 
# @section copyright Copyright
#
# gen_invoque - part of Trampoline OS
#
# gen_invoque is copyright (c) IRCCyN 2009+
# Trampoline is copyright (c) IRCCyN 2005+
# Copyright ESEO for function and data structures documentation and ARM port
# gen_invoque and Trampoline are protected by the French intellectual
# property law.
#
# gen_invoque is distributed under the GNU Public Licence v2
#
# @section infos File informations
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

import re
import sys
import getopt
from string import Template

def usage():
    print "usage: gen_invoque.py [-e<extension>]"
    
def main(argv):
    
    try:
        opts,args = getopt.getopt(argv,"e:","extension=")
    except getopt.GetoptError, err:
        print str(err)
        usage()
        sys.exit(2)
    
    extension = "s"
    for o,a in opts:
        if o == "-e":
            extension = a
                
    # get the header file
    try:
        result = open("../invoque.header").read()
        subs = Template(result)
        result = subs.substitute(EXT=extension)
    except:
        print "warning: ../invoque.header is missing"
        result = ""
    # get the heading directive file
    try:
        result = result + open("invoque.tpl").read()
    except:
        print "warning: invoque.tpl is missing"
    # get the template files if it exists
    tpl_file = "service.tpl"
    try:
        tpl_fd = open(tpl_file,'r')
        tpl = tpl_fd.read()
        tpl_fd.close()
        subs = Template(tpl)
        
        try:
            exp = re.compile("#define OSServiceId_([A-Za-z0-9_]*)")
            # get the tpl_os_service_ids.h file
            tosi_fd = open("../../os/tpl_os_service_ids.h",'r')
            for line in tosi_fd:
                found = exp.search(line)
                if found:
                    service = found.group(1)
                    if service == "StartOS":
                        fct = "tpl_start_os"
                    else:
                        fct = service
                    scall = subs.substitute(SYSCALLNAME=service,SYSCALLFCT=fct)
                    result = result + scall

            result = result + "/* End of file tpl_invoque." + extension + " */\n"
            
            try:
                res_fd = open("tpl_invoque."+extension,'w')
                res_fd.write(result);
            except:
                print "error: unable to create tpl_invoque."+extension

        except:
            print "error: tpl_os_service_ids.h file is not available"
    except:
        print "error: template file " + tpl_file + " is not readable"


if __name__ == "__main__":
	main(sys.argv[1:])
