../../../../goil/makefile-macosx/goil --target=virt-v7/armv7ve --templates=../../../../goil/templates/ firmware.oil
./make.py
# copy firmware.elf.bin to a directory where XVisor img will be built
cp firmware.elf.bin ~/vboxshare/freenivi/firmware.bin
arm-none-eabi-objdump -x firmware.elf > firmware.elf.hd
arm-none-eabi-objdump -dS firmware.elf > firmware.elf.dump
