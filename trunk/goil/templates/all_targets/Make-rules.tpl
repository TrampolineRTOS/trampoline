# Configuration file for the Makefile process.
# Note: if the target does not use the Makefile build system, this file is not used.
# The file is automatically generated by goil the first time and will not be overwritten. 
# To get a new default Make-rules file, you should simply remove the current file and call
# the goil compiler one time.

CC=gcc
LD=gcc

#############################################################################
# PATH CONFIGURATION: 
#############################################################################
# Trampoline root path to source code.
TPL_BASE_PATH = ..

#############################################################################
# OIL CONFIGURATION
#############################################################################
# Goil OIL compiler tool configuration.
# If the GOIL_TEMPLATE_PATH is commented, the default template path is used
# (it can be saved in the .profile file).
GOIL_COMPILER = goil
$GOIL_TEMPLATE_PATH$

#############################################################################
# TARGET CONFIGURATION
#############################################################################

# Targets at this date are:
# * posix-libpcl (requires the portable libpcl on your system) 
# * Hitachi h8300h
# Some targets does not use Makefile (c166, HCS12, ...)
TARGET=posix-libpcl

# arch may be:
# * libpcl
# * h8300h
GOIL_TARGET =$GOIL_TARGET$

# name of the generated executable
EXEC    =  trampoline

#############################################################################
# DOXYGEN tool
#############################################################################
# The doxygen tool is used to extract both user and developpment 
# documentation from the source code. 
# See http://www.stack.nl/~dimitri/doxygen/
# You should also install Graphviz dot tool to build dependancy graph in
# the documentation:
# see http://www.graphviz.org/
DOXYGEN = doxygen

# vim:ft=make
