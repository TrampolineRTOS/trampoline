#############################################################
### THE TRAMPOLINE MULTICORE INSTALLATION GUIDE FOR LINUX ###
#############################################################

1. First you need the NXP build tools for PowerPC VLE. You can either download and install the S32 Design Studio IDE for Power Architecture at NXP website or compile it from the source code.
Once you have a folder named powerpc-eabivle-*_* you may add this sort of line to your .bashrc file:

export PATH=$PATH:$HOME/powerpc-eabivle-4_9/bin

for instance if this folder is in your home directory.

The build tools are 32-bits binaries so if you experiment a "file not found" error while executing the build tools you may install some packages so your 64-bits installation can launch 32-bits binaries.

Be sure the libc is present in this folder since it was not the case for me. So you should have a lib folder in the powerpc-eabivle-4_9/powerpc-eabivle folder. This lib folder should contains libc.a and arch dependant library folders like "e200zx". If it's not present, you can grab this folder from the S32 Design Studio IDE for Power Architecture like I did. (copy paste in the right place). When you compile if a symbol like "memset" is not found it may be because the libc is not present in the right place.

2. Then you need the Lautherbach T32 software to use the NEXUS interface. If you have the CD then it's great for you! Otherwise you may find a "Lautherbach" folder in Kamel's or Paul's computer. Copy the Lautherbach folder in your home folder. Then add this sort of lines tu your .bashrc file:

export PATH=$PATH:$HOME/Lautherbach/files/bin/pc_linux64

export T32SYS=$HOME/Lautherbach/files
export T32TMP=/tmp
export T32ID=T32

It's important that you have a working temp folder. If not, you are going to see errors, and HLL might not work..
Finally you need to enable USB support. If you have udev on your computer this may be done in one line:


sudo cp Lautherbach/files/bin/pc_linux64/udev.conf/kernel_starting_2.6.32/10-lauterbach.rules /etc/udev/rules.d

3. YOU'RE DONE!

