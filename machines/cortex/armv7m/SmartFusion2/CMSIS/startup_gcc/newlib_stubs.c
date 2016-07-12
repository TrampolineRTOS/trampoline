/*******************************************************************************
 * (c) Copyright 2009-2013 Microsemi SoC Products Group.  All rights reserved.
 * 
 * Stubs for Newlib system calls.
 *  
 * SVN $Revision: 6665 $
 * SVN $Date: 2014-07-03 16:56:22 +0100 (Thu, 03 Jul 2014) $
 */
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <errno.h>

/*==============================================================================
 * Redirection of standard output to a SmartFusion2 MSS UART.
 *------------------------------------------------------------------------------
 * A default implementation for the redirection of the output of printf() to a
 * UART is provided at the bottom of this file. This redirection is enabled by
 * adding the symbol/define MICROSEMI_STDIO_THRU_MMUART0 or
 * MICROSEMI_STDIO_THRU_MMUART0 to your project settings and specifying the baud
 * rate using the MICROSEMI_STDIO_BAUD_RATE define.
 */
#ifdef MICROSEMI_STDIO_THRU_MMUART0
#ifndef MICROSEMI_STDIO_THRU_UART
#define MICROSEMI_STDIO_THRU_UART
#endif
#endif  /* MICROSEMI_STDIO_THRU_MMUART0 */

#ifdef MICROSEMI_STDIO_THRU_MMUART1
#ifndef MICROSEMI_STDIO_THRU_UART
#define MICROSEMI_STDIO_THRU_UART
#endif
#endif  /* MICROSEMI_STDIO_THRU_MMUART1 */

/*
 * Select which MMUART will be used for stdio and what baud rate will be used.
 * Default to 57600 baud if no baud rate is specified using the
 * MICROSEMI_STDIO_BAUD_RATE #define.
 */ 
#ifdef MICROSEMI_STDIO_THRU_UART
#include "../../drivers/mss_uart/mss_uart.h"

#ifndef MICROSEMI_STDIO_BAUD_RATE
#define MICROSEMI_STDIO_BAUD_RATE  MSS_UART_115200_BAUD
#endif

#ifdef MICROSEMI_STDIO_THRU_MMUART0
static mss_uart_instance_t * const gp_my_uart = &g_mss_uart0;
#else
static mss_uart_instance_t * const gp_my_uart = &g_mss_uart1;
#endif

/*------------------------------------------------------------------------------
 * Global flag used to indicate if the UART driver needs to be initialized.
 */
static int g_stdio_uart_init_done = 0;

#endif /* MICROSEMI_STDIO_THRU_UART */

/*==============================================================================
 * Environment variables.
 * A pointer to a list of environment variables and their values. For a minimal
 * environment, this empty list is adequate:
 */
char *__env[1] = { 0 };
char **environ = __env;

/*==============================================================================
 * Close a file.
 */
int _close(int file)
{
    return -1;
}

/*==============================================================================
 * Transfer control to a new process.
 */
int _execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

/*==============================================================================
 * Exit a program without cleaning up files.
 */
void _exit( int code )
{
    /* Should we force a system reset? */
    while( 1 )
    {
        ;
    }
}

/*==============================================================================
 * Create a new process.
 */
int _fork(void)
{
    errno = EAGAIN;
    return -1;
}

/*==============================================================================
 * Status of an open file.
 */
int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

/*==============================================================================
 * Process-ID
 */
int _getpid(void)
{
    return 1;
}

/*==============================================================================
 * Query whether output stream is a terminal.
 */
int _isatty(int file)
{
    return 1;
}

/*==============================================================================
 * Send a signal.
 */
int _kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

/*==============================================================================
 * Establish a new name for an existing file.
 */
int _link(char *old, char *new)
{
    errno = EMLINK;
    return -1;
}

/*==============================================================================
 * Set position in a file.
 */
int _lseek(int file, int ptr, int dir)
{
    return 0;
}

/*==============================================================================
 * Open a file.
 */
int _open(const char *name, int flags, int mode)
{
    return -1;
}

/*==============================================================================
 * Read from a file.
 */
int _read(int file, char *ptr, int len)
{
    return 0;
}

/*==============================================================================
 * Write to a file. libc subroutines will use this system routine for output to
 * all files, including stdout—so if you need to generate any output, for
 * example to a serial port for debugging, you should make your minimal write
 * capable of doing this.
 */
int _write_r( void * reent, int file, char * ptr, int len )
{
#ifdef MICROSEMI_STDIO_THRU_UART
    /*--------------------------------------------------------------------------
     * Initialize the UART driver if it is the first time this function is
     * called.
     */
    if(!g_stdio_uart_init_done)
    {
        MSS_UART_init(gp_my_uart,
                      MICROSEMI_STDIO_BAUD_RATE,
                      MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY);
                      
        g_stdio_uart_init_done = 1;
    }
    
    /*--------------------------------------------------------------------------
     * Output text to the UART.
     */
    MSS_UART_polled_tx(gp_my_uart, (uint8_t *)ptr, len);
    
    return len;
#else   /* MICROSEMI_STDIO_THRU_UART */
    return 0;
#endif  /* MICROSEMI_STDIO_THRU_UART */
}

/*==============================================================================
 * Increase program data space. As malloc and related functions depend on this,
 * it is useful to have a working implementation. The following suffices for a
 * standalone system; it exploits the symbol _end automatically defined by the
 * GNU linker. 
 */
caddr_t _sbrk(int incr)
{
    extern char _end;       /* Defined by the linker */
    static char *heap_end;
    char *prev_heap_end;
    char * stack_ptr;
    
    if (heap_end == 0)
    {
      heap_end = &_end;
    }
    
    prev_heap_end = heap_end;
    
    asm volatile ("MRS %0, msp" : "=r" (stack_ptr) );
    if(heap_end < stack_ptr)
    {
        /*
         * Heap is at an address below the stack, growing up toward the stack.
         * The stack is above the heap, growing down towards the heap.
         * Make sure the stack and heap do not run into each other.
         */
        if (heap_end + incr > stack_ptr)
        {
          _write_r ((void *)0, 1, "Heap and stack collision\n", 25);
          _exit (1);
        }
    }
    else
    {
        /*
         * If the heap and stack are not growing towards each other then use the
         * _eheap linker script symbol to figure out if there is room left on
         * the heap.
         * Please note that this use case makes sense when the stack is located
         * in internal eSRAM in the 0x20000000 address range and the heap is 
         * located in the external memory in the 0xA0000000 memory range.
         * Please note that external memory should not be accessed using the
         * 0x00000000 memory range to read/write variables/data because of the
         * SmartFusion2 cache design.
         */
        extern char _eheap;     /* Defined by the linker */
        char *top_of_heap;
        
        top_of_heap = &_eheap;
        if(heap_end + incr  > top_of_heap)
        {
          _write_r ((void *)0, 1, "Out of heap memory\n", 25);
          _exit (1);
        }
    }
  
    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

/*==============================================================================
 * Status of a file (by name).
 */
int _stat(char *file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

/*==============================================================================
 * Timing information for current process.
 */
int _times(struct tms *buf)
{
    return -1;
}

/*==============================================================================
 * Remove a file's directory entry.
 */
int _unlink(char *name)
{
    errno = ENOENT;
    return -1;
}

/*==============================================================================
 * Wait for a child process.
 */
int _wait(int *status)
{
    errno = ECHILD;
    return -1;
}



