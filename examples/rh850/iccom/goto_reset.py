import time
ClearConsole()

debugger.Stop()
time.sleep(2)

print "Set Reset PC"
debugger.Register.SetValue("PC", 0x200)

