../../../../goil/makefile-macosx/goil --target=virt-v7/armv7ve --templates=../../../../goil/templates/ tracking.oil
./make.py
cp tracking.elf.bin ~/vboxshare/freenivi/firmware.bin
arm-none-eabi-objdump -x tracking.elf > tracking.elf.hd
arm-none-eabi-objdump -dS tracking.elf > tracking.elf.dump
