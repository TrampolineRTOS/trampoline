/*******************************************************************************
 * (c) Copyright 2009-2015 Microsemi SoC Products Group.  All rights reserved.
 * 
 * SmartFusion2 Microcontroller Subsystem (MSS) Watchdog bare metal software
 * driver.
 *
 * SVN $Revision: 7755 $
 * SVN $Date: 2015-09-04 20:33:57 +0530 (Fri, 04 Sep 2015) $
 */
/*=========================================================================*//**
  @section intro_sec Introduction
  The SmartFusion2™ microcontroller subsystem (MSS) includes a watchdog timer
  used to detect system lockups. This software driver provides a set of
  functions for controlling the MSS watchdog as part of a bare metal system
  where no operating system is available. The driver can be adapted for use as
  part of an operating system, but the implementation of the adaptation layer
  between the driver and the operating system's driver model is outside the
  scope of the driver.
  
  The MSS watchdog driver provides support for the following features:
    - Initialization of the MSS watchdog
    - Reading the current value and status of the watchdog timer
    - Refreshing the watchdog timer value
    - Enabling, disabling and clearing time-out and wake-up interrupts.
    
  @section hw_dependencies Hardware Flow Dependencies
  The MSS watchdog must be configured by the SmartFusion2 MSS configurator in
  the Libero hardware flow before using this driver in a firmware project. The
  MSS configurator is responsible for the configuration of the MSS watchdog's
  mode of operation, reload value and refresh window. The MSS configurator sets
  the power-on reset state of the system registers that control the
  configuration of the MSS watchdog.
  The MSS watchdog configuration options are as follows:
    - Enable or disable the watchdog after a power-on or system reset
    - Generate a system reset or an interrupt if a watchdog counter timeout
      occurs
    - Set the reload value. This is the value that is loaded into the watchdog
      counter when it is refreshed
    - Set the counter threshold value. This sets up permitted and forbidden
      refresh windows for the watchdog counter
    - Lock the system register controlling watchdog enable/disable and timeout
      mode to the selected configuration (read-only) or allow it to be modified
      by firmware
  This driver assumes that the Libero hardware flow enables the MSS watchdog,
  selects its timeout mode and locks the system register that controls the
  configuration of the MSS watchdog. If you want to have firmware control of
  the MSS watchdog enable/disable and its timeout mode, you must ensure that
  the MSS configurator allows read-write access to the system register that
  controls the configuration of the MSS watchdog. The driver does not provide
  functions to write to this system register.
  The base address, register addresses and interrupt number assignment for the
  MSS watchdog block are defined as constants in the SmartFusion2 CMSIS HAL. You
  must ensure that the latest SmartFusion2 CMSIS HAL is included in the project
  settings of the software tool chain used to build your project and that it is
  generated into your project.
  
  @section theory_op Theory of Operation
  The MSS watchdog driver functions are grouped into the following categories:
    - Initialization  and configuration
    - Reading the current value and status of the watchdog timer
    - Refreshing the watchdog timer value
    - Support for enabling, disabling and clearing time-out and wake-up interrupts.
    
  Initialization and Configuration
  The MSS configurator in the Libero hardware flow is responsible for the
  configuration of the MSS watchdog's mode of operation, reload value and
  refresh window. It configures the watchdog to generate an interrupt or a
  system reset when its counter times out. It also configures the MSS watchdog
  to be enabled or disabled when power-on reset is deasserted.
  Note: The MSS watchdog cannot be enabled or disabled by the driver.
  The MSS watchdog driver is initialized through a call to the MSS_WD_init()
  function. The MSS_WD_init() function must be called before any other watchdog
  driver functions can be called.
  The occurrence of a time out event before the last system reset can be
  detected through the use of the MSS_WD_timeout_occured() function. This
  function would be typically used at the start of the application to detect
  whether the application is starting as a result of a power-on reset or a
  watchdog reset. The time out event must be cleared through a call to function
  MSS_WD_clear_timeout_event() in order to allow the detection of subsequent
  time out events or differentiating between a Cortex-M3 initiated system reset
  and watchdog reset.

  Reading the Watchdog Timer Value and Status
  The current value of the watchdog timer can be read using the
  MSS_WD_current_value() function. The watchdog status can be read using the
  MSS_WD_status() function. These functions are typically required when using
  the watchdog configured with a permitted refresh window to check whether a
  watchdog reload is currently allowed. When the current value of the watchdog
  timer is greater than the permitted refresh window value, refreshing the
  watchdog is forbidden. Attempting to refresh the watchdog timer in the
  forbidden window will cause a reset or interrupt, depending on the watchdog
  configuration. The forbidden refresh window can be disabled by the MSS
  configurator in the hardware flow by specifying a permitted refresh window
  value equal to or higher than the watchdog reload value.
  
  Refreshing the Watchdog Timer Value
  The watchdog timer value is refreshed using the MSS_WD_reload() function. The
  value reloaded into the watchdog timer down-counter is specified in the Libero
  hardware flow using the MSS configurator.

  Interrupt Control
  The watchdog timer can generate interrupts instead of resetting the system
  when its down counter timer expires. The MSS watchdog driver provides the
  following functions to control timeout interrupts:
    - MSS_WD_enable_timeout_irq
    - MSS_WD_disable_timeout_irq
    - MSS_WD_clear_timeout_irq
  The watchdog timer is external to the Cortex-M3 processor core and operates
  even when the Cortex-M3 is in sleep mode. A wakeup interrupt can be generated
  by the watchdog timer to wake up the Cortex-M3 when the watchdog timer value
  reaches the permitted refresh window while the Cortex-M3 is in sleep mode. The
  MSS watchdog driver provides the following functions to control wakeup
  interrupts:
    - MSS_WD_enable_wakeup_irq
    - MSS_WD_disable_wakeup_irq
    - MSS_WD_clear_wakeup_irq
    
 *//*=========================================================================*/

#ifndef MSS_WATCHDOG_H_
#define MSS_WATCHDOG_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "../../CMSIS/m2sxxx.h"
#include "../../CMSIS/mss_assert.h"

/***************************************************************************//**
 * The MSS_WDOG_TIMEOUT_IRQ_ENABLE_BIT_MASK macro is a bit mask specifying the
 * bit used to enable the time out interrupt within the watchdog's WDOGCONTROL
 * register.
 */
#define MSS_WDOG_TIMEOUT_IRQ_ENABLE_BIT_MASK  (uint32_t)0x00000001U

/***************************************************************************//**
  The MSS_WDOG_WAKEUP_IRQ_ENABLE_BIT_MASK macro is a bit mask specifying the bit
  used to enable the wake up interrupt within the watchdog's WDOGCONTROL
  register.
 */
#define MSS_WDOG_WAKEUP_IRQ_ENABLE_BIT_MASK   (uint32_t)0x00000002U

/***************************************************************************//**
  The MSS_WDOG_TIMEOUT_IRQ_CLEAR_BIT_MASK macro is a bit mask specifying the bit
  used to clear the time out interrupt within the watchdog's WDOGRIS register.
 */
#define MSS_WDOG_TIMEOUT_IRQ_CLEAR_BIT_MASK   (uint32_t)0x00000001U

/***************************************************************************//**
  The MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK macro is a bit mask specifying the bit
  used to clear the wake up interrupt within the watchdog's WDOGRIS register.
 */
#define MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK    (uint32_t)0x00000002U

/***************************************************************************//**
  The MSS_WDOG_REFRESH_KEY macro holds the magic value which will cause a reload
  of the watchdog's down counter when written to the watchdog's WDOGREFRESH
  register.
 */
#define MSS_WDOG_REFRESH_KEY    (uint32_t)0xAC15DE42U

/***************************************************************************//**
  The MSS_WD_init() function initializes the MSS watchdog timer. It disables
  interrupt generation and clears any pending watchdog interrupts. It also
  refreshes the watchdog counter if the current count is within the permitted
  refresh window.
  Note: This function does not enable or disable the watchdog; that is the
        responsibility of the hardware flow.
  Note: Calling this function does not affect the hardware reported time out
        event indicator reported by a call to function MSS_WD_timeout_occured().
        It is therefore allowed to call the MSS_WD_init() function before
        calling MSS_WD_timeout_occured().
        
  @return
    This function does not return a value.
 */
static __INLINE void MSS_WD_init(void)
{
    uint32_t wdg_value;
    
    /* Disable interrupts. */
    WATCHDOG->WDOGCONTROL &= ~(MSS_WDOG_TIMEOUT_IRQ_ENABLE_BIT_MASK | MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK);
    
    /* Clear any existing interrupts. */
    WATCHDOG->WDOGRIS = MSS_WDOG_TIMEOUT_IRQ_CLEAR_BIT_MASK | MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK;
    
    /* Clear any pending wakeup interrupt from Cortex-M3 NVIC */
    NVIC_ClearPendingIRQ(WdogWakeup_IRQn);
    
    /* Reload watchdog with new load value if in allowed window. */
    wdg_value = WATCHDOG->WDOGVALUE;
    if(wdg_value < WATCHDOG->WDOGMVRP)
    {
        WATCHDOG->WDOGREFRESH = MSS_WDOG_REFRESH_KEY;
    }
}

/***************************************************************************//**
  The MSS_WD_reload() function causes the watchdog to reload its down-counter
  timer with the load value configured through the the MSS configurator in the
  hardware flow. This function must be called regularly to avoid a system reset
  or a watchdog interrupt.
 
  @return
    This function does not return a value.
 */
static __INLINE void MSS_WD_reload(void)
{
    WATCHDOG->WDOGREFRESH = MSS_WDOG_REFRESH_KEY;
}

/***************************************************************************//**
  The MSS_WD_current_value() function returns the current value of the
  watchdog's down-counter.
 
  @return
    This function returns the current value of the watchdog’s down-counter as
    a 32-bit unsigned integer.
 */
static __INLINE uint32_t MSS_WD_current_value(void)
{
    return WATCHDOG->WDOGVALUE;
}

/***************************************************************************//**
  The MSS_WD_status() function returns the refresh status of the watchdog.
 
  @return 
    This function returns the refresh status of the watchdog. A value of 0
    indicates that watchdog’s down-counter is within the forbidden window and
    that a reload should not be done. A value of 1 indicates that the watchdog’s
    down counter is within the permitted window and that a reload is allowed.
 */
static __INLINE uint32_t MSS_WD_status(void)
{
    return WATCHDOG->WDOGSTATUS;
}

/***************************************************************************//**
  The MSS_WD_enable_timeout_irq() function enables the watchdog’s timeout
  interrupt which is connected to the Cortex-M3 NMI interrupt. The NMI_Handler()
  function will be called when a watchdog timeout occurs.
  Note: An NMI_handler() default implementation is weakly defined in the 
        SmartFusion2 CMSIS HAL. You must provide your own implementation of the
        NMI_Handler() function, that will override the default implementation,
        to suit your application.
        
  @return
    This function does not return a value.
 
  Example:
  @code
  #include "mss_watchdog.h"
  int main( void )
  {
      MSS_WD_init();
      MSS_WD_enable_timeout_irq();
      for (;;)
      {
          main_task();
      }
  }
 
  void NMI_Handler( void )
  {
      process_timeout();
      MSS_WD_clear_timeout_irq();
  }
  @endcode
 */
static __INLINE void MSS_WD_enable_timeout_irq(void)
{
    WATCHDOG->WDOGCONTROL |= MSS_WDOG_TIMEOUT_IRQ_ENABLE_BIT_MASK;
}

/***************************************************************************//**
  The WD_disable_timeout_irq() function disables the generation of the NMI
  interrupt when the watchdog times out.
 
  @return
    This function does not return a value.
 */
static __INLINE void MSS_WD_disable_timeout_irq(void)
{
    WATCHDOG->WDOGCONTROL &= ~MSS_WDOG_TIMEOUT_IRQ_ENABLE_BIT_MASK;
}

/***************************************************************************//**
  The MSS_WD_enable_wakeup_irq() function enables the SmartFusion2 wakeup
  interrupt. The WdogWakeup_IRQHandler() function will be called when a wakeup
  interrupt occurs.
  Note: A WdogWakeup_IRQHandler() default implementation is weakly defined in
        the SmartFusion2 CMSIS HAL. You must provide your own implementation of
        the WdogWakeup_IRQHandler() function, which will override the default
        implementation, to suit your application.
        
  @return
    This function does not return a value.
 
  Example:
  @code
  #include "mss_watchdog.h"
  int main( void )
  {
      MSS_WD_init();
      MSS_WD_enable_wakeup_irq();
      for (;;)
      {
          main_task();
          cortex_sleep();
      }
  }
 
  void WdogWakeup_IRQHandler( void )
  {
      process_wakeup();
      MSS_WD_clear_wakeup_irq();
  }
  @endcode
 */
static __INLINE void MSS_WD_enable_wakeup_irq(void)
{
    WATCHDOG->WDOGCONTROL |= MSS_WDOG_WAKEUP_IRQ_ENABLE_BIT_MASK;
    NVIC_EnableIRQ( WdogWakeup_IRQn );
}

/***************************************************************************//**
  The MSS_WD_disable_wakeup_irq() function disables the generation of the
  SmartFusion2 wakeup interrupt. 
 
  @return
    This function does not return a value.
 */
static __INLINE void MSS_WD_disable_wakeup_irq(void)
{
    WATCHDOG->WDOGCONTROL &= ~MSS_WDOG_WAKEUP_IRQ_ENABLE_BIT_MASK;
}

/***************************************************************************//**
  The MSS_WD_clear_timeout_irq() function clears the watchdog’s timeout
  interrupt which is connected to the Cortex-M3 NMI interrupt. Calling
  MSS_WD_clear_timeout_irq() results in clearing the Cortex-M3 NMI interrupt.
  Note: You must call the MSS_WD_clear_timeout_irq() function as part of your
        implementation of the NMI_Handler() timeout interrupt service routine
        (ISR) in order to prevent the same interrupt event retriggering a call
        to the timeout ISR.
        
  @return
    The example below demonstrates the use of the MSS_WD_clear_timeout_irq()
    function as part of the NMI interrupt service routine.

    Example:
  @code
  void NMI_Handler( void )
  {
      process_timeout();
      MSS_WD_clear_timeout_irq();
  }
  @endcode
 */
static __INLINE void MSS_WD_clear_timeout_irq(void)
{
    WATCHDOG->WDOGRIS = MSS_WDOG_TIMEOUT_IRQ_CLEAR_BIT_MASK;
    /*
     * Perform a second write to ensure that the first write completed before 
     * returning from this function. This is to account for posted writes across
     * the AHB matrix. The second write ensures that the first write has
     * completed and that the interrupt line has been de-asserted by the time
     * the function returns. Omitting the second write may result in a delay
     * in the de-assertion of the interrupt line going to the Cortex-M3 and a
     * retriggering of the interrupt.
     */
    WATCHDOG->WDOGRIS = MSS_WDOG_TIMEOUT_IRQ_CLEAR_BIT_MASK;
}

/***************************************************************************//**
  The MSS_WD_clear_wakeup_irq() function clears the wakeup interrupt. This
  function also clears the interrupt in the Cortex-M3 interrupt controller
  through a call to NVIC_ClearPendingIRQ().
  Note: You must call the MSS_WD_clear_wakeup_irq() function as part of  your
        implementation of the WdogWakeup_IRQHandler() wakeup interrupt service
        routine (ISR) in order to prevent the same interrupt event retriggering
        a call to the wakeup ISR.
        
  @return
    This function does not return a value.

    Example:
    The example below demonstrates the use of the MSS_WD_clear_wakeup_irq() function
    as part of the wakeup interrupt service routine.  
    @code
    void WdogWakeup_IRQHandler( void )
    {
        do_interrupt_processing();
        
        MSS_WD_clear_wakeup_irq();
    }
    @endcode
*/
static __INLINE void MSS_WD_clear_wakeup_irq(void)
{
    WATCHDOG->WDOGRIS = MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK;
    /*
     * Perform a second write to ensure that the first write completed before 
     * returning from this function. This is to account for posted writes across
     * the AHB matrix. The second write ensures that the first write has
     * completed and that the interrupt line has been de-asserted by the time
     * the function returns. Omitting the second write may result in a delay
     * in the de-assertion of the interrupt line going to the Cortex-M3 and a
     * retriggering of the interrupt.
     */
    WATCHDOG->WDOGRIS = MSS_WDOG_WAKEUP_IRQ_CLEAR_BIT_MASK;
}

/***************************************************************************//**
  The MSS_WD_timeout_occured() function reports the occurance of a timeout
  event. It can be used to detect if the last Cortex-M3 reset was due to a
  watchdog timeout or a power-on reset.
 
  @return
    0: No watchdog timeout event occured.
    1: A timeout event occured.

  Example:
  @code
  #include "mss_watchdog.h"
  int main( void )
  {
      uint32_t wdg_reset;
      MSS_WD_init();
      wdg_reset = MSS_WD_timeout_occured();
      if(wdg_reset)
      {
          log_watchdog_event();
          MSS_WD_clear_timeout_event();
      }
      
      for(;;)
      {
          main_task();
      }
  }
*/
static __INLINE uint32_t MSS_WD_timeout_occured(void)
{
    return SYSREG->WDOGTIMEOUTEVENT;
}

/***************************************************************************//**
  The MSS_WD_clear_timeout_event() function clears the hardware's report of a
  watchdog timeout event. This function would typically be called after a call
  to MSS_WD_timeout_occured() to clear the hardware's report of a timeout event
  and therefore enable detection of subsequent timeout events.
 
  @return
    This function does not return a value.
    
  Example:
  @code
  #include "mss_watchdog.h"
  int main( void )
  {
      uint32_t wdg_reset;
      MSS_WD_init();
      wdg_reset = MSS_WD_timeout_occured();
      if(wdg_reset)
      {
          log_watchdog_event();
          MSS_WD_clear_timeout_event();
      }
      
      for(;;)
      {
          main_task();
      }
  }
*/
static __INLINE void MSS_WD_clear_timeout_event(void)
{
    /* Clear WDOGTIMEOUTEVENT system register. */
    SYSREG->WDOGTIMEOUTEVENT = 1u;
}

#ifdef __cplusplus
}
#endif

#endif /* MSS_WATCHDOG_H_ */
