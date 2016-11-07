#! /usr/bin/python

#
# Trampoline Test Suite
#
# Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
# Trampoline Test Suite is protected by the French intellectual property law.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; version 2
# of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

# This file uses trace32 t32api.so/t32api64.so, copyright (c) LAUTERBACH.

import platform
import ctypes
import sys
import argparse

parser = argparse.ArgumentParser(description='Lauterbach test launcher')
parser.add_argument('-d', metavar="testDir", type=str, nargs=1,
                    required=True, help='test directory')
parser.add_argument('-e', metavar="exe", type=str, nargs=1,
                    required=True, help='executable name')
parser.add_argument('-o', metavar="orti", type=str, nargs=1,
                    required=True, help='orti file')
args = parser.parse_args()

# Get arguments
testDir = args.d.pop(0)
exe = args.e.pop(0)
orti = args.o.pop(0)

# Load t32 library
if ctypes.sizeof(ctypes.c_voidp)==4:
  t32api = ctypes.CDLL("./t32api.so")
else:
  t32api = ctypes.CDLL("./t32api64.so")

# Set connexion configuration
t32api.T32_Config(b"NODE=",b"localhost")
t32api.T32_Config(b"PORT=",b"20000")
t32api.T32_Config(b"PACKLEN=",b"1024")
# Connect
t32api.T32_Init()
t32api.T32_Attach(1)

# Set application path and exe name in lauterbach.cmm
t32api.T32_Cmd(b"&appPath=\"" + testDir + "\"")
t32api.T32_Cmd(b"&exeName=\"" + exe + "\"")
t32api.T32_Cmd(b"&ortiPath=\"" + orti + "\"")
# Run lauterbach.cmm
t32api.T32_Cmd(b"do lauterbach.cmm")

t32api.T32_Exit()
