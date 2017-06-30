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
# @section infos File informations
#
# $Date$
# $Rev$
# $Author$
# $URL$
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
arch_execute()
{
  if [ -z "${PULPINO_PATH}" ]; then
    echo "PULPINO_PATH is not set"
    exit 1
  fi

  tcsh -c env\ PULP_CORE=riscv\ VSIM_DIR=${PULPINO_PATH}/vsim\ TB_TEST=""\ vsim\ -c\ -64\ -do\ 'source\ tcl_files/run.tcl\;\ run\ -a\;\ exit\;' > /dev/null
  cat ./stdout/*
  exit $?
}

arch_execute_fpga()
{
  scp slm_files/spi_stim.txt $FPGA_HOSTNAME:/root/$1.spi
  ssh -t $FPGA_HOSTNAME /root/spiload --timeout=2 /root/$1.spi > $1.out
  cat $1.out | grep PULPino | tr -d '\r' | cut -d' ' -f 2-
}

# -----------------------------------------------------------------------------
# arch_compile
# -----------------------------------------------------------------------------
#   Compile a test. In posix, we use a python script.
#   $1 : file to execute
arch_compile()
{
  ./build.py
}

# =============================================================================
# Call to the requested function
#

# TODO : Check valid function requested

# =============================================================================
# Call to the requested function
#

$@
