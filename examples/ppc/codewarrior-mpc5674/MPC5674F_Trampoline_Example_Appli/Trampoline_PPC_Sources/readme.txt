/*
***
*/
 
 - The Trampoline_PPC_Sources directory contains sources files that were originally copied from mpc5643 directory example.
 "tpl_init-term" and "tpl_machine_ppc" was modified to adapt new types declared in "tpl_os_std_types.h" (ie. u32 -> uint32)
 
 - The file "tpl_call_trusted_fct.s" has been excluded form Build since for this example we don't need those trusted functions (CallTrustedFunction
   is not declared in tpl_invoque.s).
 
 - "tpl_tick.s" has been excluded from build and we will use timer as a source tick.  
 
 - Define is add in tpl_app_define.h to select the PIT as source for the system counter.
 
 - Modifications brought in all project files relative to trampoline mpc5674f porting are commented with the key word  "MPC5674F_Porting_Modif".
 
 - For the case of files related to PPC sources, mainly tpl_it_handler and tpl_dispach assembly files have been affected:
 	* Align tpl_it_handler and tpl_sc_handler to support the new version of kernel files. The call of tpl_run_elected function to put the elected process 
 	  in the running state (without this we never switch between tasks)
 	* Modify the offset of some fields since the kernel stack structure has been changed by the integration of elected state for process.     
 	
 - tpl_timers.c and tpl_it_management.s have been also modified to support mpc5674f specificities.
 
 - tpl_it_handler and tpl_sc_handler are have been also modified to support hw mode for the INTC (interrupt controller for mpc5674f). 
   The purpose of   this modification is to support ISR1 in oil description. Some others functions has been changed to support this mode, 
   ex: tpl_init_interrupts function. 