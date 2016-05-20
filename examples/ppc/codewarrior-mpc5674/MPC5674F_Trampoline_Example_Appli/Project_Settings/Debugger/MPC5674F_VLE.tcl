# This configuration script is compatible with MPC567xF MCUs.
# Features:
# - Disables the Software Watchdog Timer (SWT) and Core WDT
# - Initializes the core MMU with a single 4GB page to allow application
# start debug
# - Initializes the system ECC SRAM
# - Sets the PC to the application start address from the internal flash
# If the entry point isn't available PC is set to BAM start address.
#
# Rev. 1.3 - fix reading RCHW 
#
# VERSION: 1.3

######################################
# Initialize target variables
######################################
# var booke_vle: BOOKE = booke, VLE = vle
set booke_vle vle

######################################
## Register group definitions
######################################

# GPR registrer group
set GPR_GROUP "General Purpose Registers/"

#################################################
# Initialize a RAM 'range' from 'start' address,
# downloading the init program at 0x4000_0000.
#################################################
proc init_ram {start range} {
      global GPR_GROUP
      global booke_vle

    puts "init ECC SRAM $start:$range"
    # default SRAM address
    set pstart 0x40000000
    # the offset from the given start address
    # at which the init prgram starts to init SRAM
    set offset 0x0
    # stmw write page size = 128 = 4bytes * 32 GPRS
    set psize 0x80

    if {$start == $pstart} {
        # init first 4 bytes (mem access) x 128 = 512
        # bytes to avoid reading the memory around PC
        # after stopping the core
        mem $start 256 = 0x0
        # base init address
        set offset 0x80
    }

    # address to start initialization
    set start [expr {$start + $offset}]
    
    # load add into GPR
    reg ${GPR_GROUP}GPR11 %d = $start

    # compute actual times stmw is called
    # and set counter
    set c [expr ((($range - $offset)/$psize))]
    reg ${GPR_GROUP}GPR12 %d = $c

    # execute init ram code
    if {$booke_vle == "vle"} {
        #mtctr r12
        mem $pstart = 0x7D8903A6
        #stmw r0,0(r11)
        mem [format %x [expr $pstart + 0x4]] = 0x180B0900
        #addi r11,r11,128
        mem [format %x [expr $pstart + 0x8]] = 0x1D6B0080
        #bdnz -8
        mem [format %x [expr $pstart + 0xc]] = 0x7A20FFF8
        # infinte loop
        #se_b *+0
        mem [format %x [expr $pstart + 0x10]] = 0xE8000000
    } else {
        #mtctr r12
        mem $pstart = 0x7D8903A6
        #stmw r0,0(r11)
        mem [format %x [expr $pstart + 0x4]] = 0xBC0B0000
        #addi r11,r11,128
        mem [format %x [expr $pstart + 0x8]] = 0x396B0080
        #bdnz -8
        mem [format %x [expr $pstart + 0xc]] = 0x4200FFF8
        # infinte loop
        #se_b *+0
        mem [format %x [expr $pstart + 0x10]] = 0x48000000    
    }
    
    # set PC to the first init instruction
    reg ${GPR_GROUP}PC = $pstart
    # execute init ram code
    # timeout 1 second to allow the code to execute
    go 1
    stop
    if {[reg ${GPR_GROUP}PC -np] != [expr $pstart + 0x10]} {
        puts  "Exception occured during SRAM initialization."
    } else {
        puts "SRAM initialized."
    }
}

#################################################################
# Tries to obtain the program entry point from binary debug info
# or by searching for the first flash boot sector. If neither
# is succesfull it returns the BAM start address.
#################################################################
proc get_entry_point {} {
    puts "Get application entry point ..."
    # check symbolic names first
    set reset_vector_addr 0x3
    catch {set reset_vector_addr [evaluate __startup]}
    # If no debug info available search for a FLASH boot sector
    if {$reset_vector_addr == 0x3} {
        # RCHW addresses of each Flash boot sector
        set SECTORS_ADD [list 0x0000 0x4000 0x10000 0x1C000 0x20000 0x30000]
        puts "Searching for boot sectors ..."
        set rchw_value 0x0
        foreach rchw $SECTORS_ADD {
            catch {set rchw_value [mem $rchw -np]}
            if {[expr $rchw_value & 0xFF0000] == 0x5A0000} {
                catch {set reset_vector_addr [mem [format "0x%x" [expr $rchw + 0x4]] -np]}
                set reset_vector_addr [format "0x%x" [expr $reset_vector_addr & 0xFFFFFFFF]]
                puts "Found boot sector at $rchw and entry point at $reset_vector_addr."  
                break
            }
        }        
    }
    if {$reset_vector_addr == 0x3} {
        puts "No entry point available. Set entry point to BAM start address."
        set reset_vector_addr 0xFFFFFFFC
    }
    return $reset_vector_addr
}

proc mpc567xf_init {} {
      global GPR_GROUP
      global booke_vle
    
    # special purpose register group
    set SPR_GROUP "e200z760n3 Special Purpose Registers/"
    
    #TLB1 registers group
    set TLB1_GROUP "regPPCTLB1/"

    puts "Start initializing the MCU ..."
    reset hard
            
    # Explicitly stop core
    stop

    # reset watch dog timer
    reg ${SPR_GROUP}TCR = 0x0

    # TLB entry 0: base address = 0x0000_0000, 4GB, not guarded, cache inhibited, access all
    if {$booke_vle == "vle"} {
        # VLE page
        reg ${TLB1_GROUP}MMU_CAM0 = 0xB0000008FE0800000000000000000001
    } else {
        # BOOKE page
        reg ${TLB1_GROUP}MMU_CAM0 = 0xB0000008FC0800000000000000000001
    }

    # Disable Watchdog Timer
    mem 0xFFF38010 = 0x0000C520
    mem 0xFFF38010 = 0x0000D928
    mem 0xFFF38000 = 0x8000010A

    # Initialize core interrupts in order to catch any exceptions during
    # MCU initialization. The following sequence queries symbolics to
    # obtain the address of the wellknown symbol "ivor_branch_table".
    set ivor_table 0x40000000
    set r [catch {set ivor_table [evaluate ivor_branch_table]}]
    # set IVPR vector base table high 16-bit and IVOR0 lower 16-bit
    
    set ivor0 0x[format %x [expr $ivor_table & 0xFFFF]]
    reg ${SPR_GROUP}IVPR = 0x[format %x [expr $ivor_table & 0xFFFF0000]]
    # Initiliaze only the first 16 IVORs
    for {set i 0} {$i < 16} {incr i} {
        # The IVOR branch table must have a 16 byte aligment.
        reg ${SPR_GROUP}IVOR${i} = 0x[format %x [expr $ivor0 + $i * 0x10]]
    }
    
    # enable SPE and Debug interrupts
    reg ${SPR_GROUP}MSR = 0x2002000

    # SRAM memory sizes for supported MCUs.
    # MPC567xF, where x  = 3, 4; below key = x
    # 256K - 0x40000
    # 192K - 0x30000
    set mem_size(3) 0x30000
    set mem_size(4) 0x40000
    set current_cfg 4
    
    # detects the current MCU
    set SIUL_MIDR1 0x50000
    puts "reading SIUL.MIDR1 ..."
    set r [catch {set SIUL_MIDR1 [mem 0xC3F90004]}]
    if {$r == 0} {
        # get x from 567x
        set r [format %x [expr ($SIUL_MIDR1/0x100000) & 0xFFF]]
        set rx [expr ($SIUL_MIDR1 & 0xF0000) / 0x10000]
        if {$r == 567 && [info exists mem_size($rx)]} {
            puts [format "Current MCU found as MPC567%sF mask 0x%02x" $rx [expr ($SIUL_MIDR1 & 0xFF)]]
            set current_cfg $rx
        } else {
            puts  "Found MCU ID $r$rx. The device isn't supported by current script."
        }
    } else {
        puts  "Unable to detect MCU."
    }

    # initialize ECC SRAM for current MCU derivative
    init_ram 0x40000000 $mem_size($current_cfg)

    # initialize PC after reset with application start address or BAM otherwise
    reg ${GPR_GROUP}PC = [get_entry_point]
    # set SP to an unaligned (4bytes) to avoid creating invalid stack frames
    reg ${GPR_GROUP}SP = 0x3

    puts "Finish initializing the MCU."
}

########################################
## Environment Setup: 32bit meme access
## or numbers start with hex notation.
########################################
proc envsetup {} {
    radix x 
    config hexprefix 0x
    config MemIdentifier v 
    config MemWidth 32 
    config MemAccess 32 
    config MemSwap off
}
 
# env setup
envsetup

# main entry
mpc567xf_init
