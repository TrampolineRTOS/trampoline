#include "simtec_driver_adapter.h"

#ifdef SIMTEC_DEFAULT_DRIVERS
#include "default_drivers/horloge.h"
#include "default_drivers/timer.h"
#include "default_drivers/interruption.h"
#include "default_drivers/memoire.h"

/*
 * System timer registers
 */
#define TMEN (*((u32*)0xB8001004))
#define TMRLR (*((u32*)0xB8001008))
#define TMOVFR (*((u32*)0xB8001010))

/*
 * Power management registers
 */
#define CLKSTP (*((u32*)0xB8000004))

/*
 * CLKSTP register bits
 */
#define CPU_HALT (1 << 2)
#define TIC_CLK_DISABLED (1 << 1)
#define SYSTEM_STANDBY (1 << 7)

#endif /* SIMTEC_DEFAULT_DRIVERS */

void simtec_clock_gen_setup_defaults ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  Horloge_initialiser ();
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_int_ctrl_setup_defaults ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  Interruption_initialiser ();
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_memory_setup_defaults ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS 
	if (!Memoire_execution_en_dram ())
	{
		Horloge_initialiser ();
		Memoire_initialiser ();
	}
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_disable_all_devices ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_setup_heartbeat_timer_1ms ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  TMOVFR = 1;  /* prevently acknoledge system timer IRQ (useful after soft reboot) */
  TMEN = 0;
  Interruption_set_priorite (INTERRUPTION_TIMER_SYSTEME, 7);
  TMRLR = 0xFFFF - 3687;
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_heartbeat_timer_start ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  TMEN = 1;
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_heartbeat_timer_ack ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  TMOVFR = 1;
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

void simtec_cpu_halt ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  CLKSTP = 0x3C;      /* key to unlock register functions */
  CLKSTP |= CPU_HALT | TIC_CLK_DISABLED;
#endif /* SIMTEC_DEFAULT_DRIVERS */ 
}

void simtec_system_standby ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  CLKSTP = 0x3C;      /* key to unlock register functions */
  CLKSTP |= SYSTEM_STANDBY;
#endif /* SIMTEC_DEFAULT_DRIVERS */
}

u32 simtec_get_interrupt_source ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  return (u32)Interruption_get_source (); 
#endif
}

void simtec_acknoledge_current_irq_level ()
{
#ifdef SIMTEC_DEFAULT_DRIVERS
  Interruption_acquitter_niveau_courant ();
#endif
}
