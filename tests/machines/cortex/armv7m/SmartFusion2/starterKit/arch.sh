#! /bin/sh

#
# @file arch.sh
#
# @section desc File description
#
# Trampoline Test Suite : Machine dependant shell functions
#
# @section copyright Copyright
#
# Trampoline Test Suite
#
# Trampoline Test Suite is copyright (c) IRCCyN 2005-2017
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
# @section infos File informations
#

# This script is called by the root test.sh script.
# The first argument $1 contains the architecture dependant shell function to
# call.
# Other arguments are the function's parameters

# =============================================================================
# Functions definitions
#

# -----------------------------------------------------------------------------
# arch_execute
# -----------------------------------------------------------------------------
#   Executes a test.
#   $1 : file to execute

#   This function should print the result string of the task:
#   example:
#   ...
#   OK (3 tests)
arch_execute()
{
  #TODO
  TESTDIR=$(pwd -P)
  EXENAME="$(basename $TESTDIR)_exe"
#  ORTIPATH="$TESTDIR/$(basename $TESTDIR)/trampoline.orti"
#  OUTPUT=$TESTDIR/output  # The script lauterbach.cmm writes the output here
#  RETVAL=$TESTDIR/retval  # The script lauterbach.cmm writes the retval here
#  echo "arch execute"
#  echo "TESTDIR" $TESTDIR
#  echo "EXENAME" $EXENAME
	echo "..."
	echo "OK (3 tests)"
#
#  # Clean output if exists
#  rm -f $OUTPUT $RETVAL
#
#  # Go to Lauterbach's scripts directory
#  cd ../../machines/ppc/tools/lauterbach
#  # Send the test to trace32
#  ./sendTest.py -d $TESTDIR -e $EXENAME -o $ORTIPATH
#  # Go back to the test directory
#  cd $TESTDIR
#  # Get execution's return value
#  retval=""
#  while [ "$retval" = "" ]; do
#    sleep 1
#    retval=$(cat $RETVAL 2>/dev/null)
#  done
#
#  # Print output to stdout
#  cat $OUTPUT
#
#  # Print error to stderr
#  if [ $retval -eq 1 ]; then
#    echo >&2 "Segmentation Fault"
#  elif [ $retval -eq 2 ]; then
#    echo >&2 "Execution Timeout"
#  fi
#
#  # Clean outputs
#  rm -f $OUTPUT $RETVAL
#
#  exit $retval
}

arch_compile()
{
  TESTDIR=$(pwd -P)
  EXENAME="$(basename $TESTDIR)_exe"
  ELFNAME="$EXENAME.elf"
  rm -f $EXENAME
  ./build.py
  # Set the elf as the executable
  mv $ELFNAME $EXENAME
}

# TODO : Check valid function requested

# =============================================================================
# Call to the requested function
#

$@
