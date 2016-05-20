/*
***
*/
- The Goil_Generated_Sources directory contains sources files that were originally copied from files generated after compilation of codewarrior mpc5516
example.

- I have excluded "stm_structure" and "tpl_ioc_api_config.c" from the build configurations because they generate compilation errors and they haven't a 
  semantic effect since their related variables are set to zero in tpl_app_define.h".
  
- Goil templates have been modified to support specific needs of the mpc5674f architecture.

- Mainly update was affected the isr_descriptor template where we have added the generation of new function for every ISR2 declared in oil file.

- Other importante function was inserted in ordrer to declare the acknowlogement function for every ISR2.

- For the hardware counters, the ACK function prototype is generated and the definition is performed in the suitable file. In our case we have used the PIT 
and the ACK function was specified in the tpl_timers.c

- Just to explain the approach adopted in the management of interrupt routines for the mpc5674f and it should operate with others ppc architectures:
	 - Independently of the interrupt type (counter, ISR2 ...), a specific function is generated to be include in interrupt handler table.
	 - With this configuration, we have the ability to include the ACK function for each interrupt source. This is primordial since for Trampoline with ppc 
	 the interrupt flag (peripheral device, software interrupt) must be cleared before the INTC end of interrupt flag.
	 - The declaration of ACK function is generated, however its implementation must be included in a user file.      
    