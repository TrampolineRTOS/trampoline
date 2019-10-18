# MSP430x small memory model port

This port is for small MSP430 CPUX targets with a few kB or RAM. It has been done to limit the amount of memory used to store a context (nearly divided  by 2 compared to the large memory model). Most MSP430s equipped with FRAMs fall into this category.

This port assumes all the code and the data, OS and application, is in the lowest 64kB (16 bits addressable).

Memory above the 64kB limit shall be used within non-preemptable application code because high 4 bits of registers will not be saved in the context when the task or ISR2 is preempted. It can also be used in a customized kernel or in kernel extension to do, for instance, checkpointing.
