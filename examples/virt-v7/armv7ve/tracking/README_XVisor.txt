		Basic Firmware on Virt-v7 Guest

The basic firmware currently sets up PIC, Timer, and UART and emulates
a dummy terminal which reponds to various commands. It also includes an
extensive MMU test suite and dhrystone benchmark.

Hardware features tested by Basic Firmware:
  - Sensitive non-priviledged instructions
  - Virtual IRQs
  - Generic Interrupt Controller (GIC)
  - Serial Port (PL011)  

Please follow the steps below to build & run Basic Firmware on Virt-v7
Guest with Xvisor running on ARM Fast Model VExpress-A15 Host:

  [1. Build environment for Xvisor]
  # export CROSS_COMPILE=arm-linux-gnueabi-

  [2. GoTo Xvisor source directory]
  # cd <xvisor_source_directory>

  [3. Configure Xvisor with Generic v7-ve default settings]
  # make ARCH=arm generic-v7-ve-defconfig

  [4. Build Xvisor & DTBs]
  # make; make dtbs

  [5. Build Basic Firmware]
  # make -C tests/arm32/virt-v7/basic

  [6. Create disk image for Xvisor]
  # mkdir -p ./build/disk/tmp
  # mkdir -p ./build/disk/system
  # cp -f ./docs/banner/roman.txt ./build/disk/system/banner.txt
  # cp -f ./docs/logo/xvisor_logo_name.ppm ./build/disk/system/logo.ppm
  # mkdir -p ./build/disk/images/arm32/virt-v7
  # ./build/tools/dtc/dtc -I dts -O dtb -o ./build/disk/images/arm32/virt-v7x2.dtb ./tests/arm32/virt-v7/virt-v7x2.dts
  # cp -f ./build/tests/arm32/virt-v7/basic/firmware.bin ./build/disk/images/arm32/virt-v7/firmware.bin
  # cp -f ./tests/arm32/virt-v7/basic/nor_flash.list ./build/disk/images/arm32/virt-v7/nor_flash.list
  # genext2fs -B 1024 -b 16384 -d ./build/disk ./build/disk.img

  [7. Create fast_model_boot.axf for running it on ARM Fast Models]
  # ${CROSS_COMPILE}gcc -nostdlib -march=armv7ve -mcpu=cortex-a15 -e start_boot -Wl,--build-id=none -Wl,-Ttext=0x80000000 -DSPIN_LOOP_ADDR=0x14000000 -DVEXPRESS_A15 -DIMAGE=build/vmm.bin -DDTB=build/arch/arm/board/generic/dts/vexpress/a15/one_guest_virt-v7.dtb -DINITRD=build/disk.img ./docs/arm/fast_model_boot.S -o build/fast_model_boot.axf

  [8. Launch ARM fast models 8.0 or higher]
  # model_shell <your_fastmodel_dir>/FastModelsPortfolio_<xxxx>/examples/FVP_VE/Build_Cortex-A15x1/Linux-Debug-GCC-<yyyy>/cadi_system_Linux-Debug-GCC-<yyyy>.so build/fast_model_boot.axf
  OR
  # model_shell64 <your_fastmodel_dir>/FastModelsPortfolio_<xxxx>/examples/FVP_VE/Build_Cortex-A15x1/Linux64-Debug-GCC-<yyyy>/cadi_system_Linux64-Debug-GCC-<yyyy>.so build/fast_model_boot.axf

  [9. Kick Guest0 for starting Basic Firmware]
  XVisor# guest kick guest0

  [10. Bind to virtual UART]
  XVisor# vserial bind guest0/uart0

  [11. Say 'hi' to Basic Firmware]
  [guest0/uart0] basic# hi

  [12. Say 'hello' to Basic Firmware]
  [guest0/uart0] basic# hello

  [13. Check various commands of Basic Firmware]
  [guest0/uart0] basic# help

  [14. Enter character seqence 'ESCAPE+x+q" return to Xvisor prompt]
  [guest0/uart0] basic# 

  (Note: replace all <> brackets based on your workspace)
  (Note: some of the above steps will need to be adapted for other
   types of ARM host)
  (Note: for more info on your desired ARM host refer docs/arm/)
  (Note: you are free to change the ordering of above steps based
   on your workspace)
