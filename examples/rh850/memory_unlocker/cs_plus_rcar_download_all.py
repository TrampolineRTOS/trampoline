
import time
ClearConsole()
print "1PE_ATK2"
print "Resetting debugger"
debugger.Reset()
time.sleep(2)
print "SYSCTRL 0x0003"
debugger.Register.SetValue("SYSCTRL.BOOTCTRL", 0x0003)
time.sleep(2)
print "CPU Stop"
debugger.Stop()
time.sleep(2)
print "HBG_CS 0x00000003"
debugger.Register.SetValue("HBG_CS0.HBGPROT0", 0x00000003)
debugger.Register.SetValue("HBG_CS1.HBGPROT0", 0x00000003)
debugger.Register.SetValue("HBG_CS2.HBGPROT0", 0x00000003)
#time.sleep(1)
print "CSRM 0x12B9B0A0"
debugger.Register.SetValue("CSRM0.CSRM0CSIFCODE", 0x12B9B0A0)
debugger.Register.SetValue("CSRM1.CSRM1CSIFCODE", 0x12B9B0A0)
debugger.Register.SetValue("CSRM2.CSRM2CSIFCODE", 0x12B9B0A0)
#time.sleep(1)
print "Download Trampoline/Hello_world"
debugger.Download.LoadModule("_build/memory_unlocker_exe.abs", downloadOption = DownloadOption.SymbolOnly, append = False, flashErase = False, vendorType = VendorType.Auto)
print "Download Trampoline/Hello_world (RUN)"
debugger.Download.Hex("_build/memory_unlocker_exe.run", offset = 0xF0000000, append = True, flashErase = False)
print "CSRM 0x12B9B0A1"
debugger.Register.SetValue("CSRM0.CSRM0CSIFCODE", 0x12B9B0A1)
debugger.Register.SetValue("CSRM1.CSRM1CSIFCODE", 0x12B9B0A1)
debugger.Register.SetValue("CSRM2.CSRM2CSIFCODE", 0x12B9B0A1)
#time.sleep(1)
print "Set Reset PC"
debugger.Register.SetValue("PC", 0x200)
#time.sleep(1)
print "Starting G4"
debugger.Go()
