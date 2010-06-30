#ifndef _ECROBOT_INTERFACE_H_
#define _ECROBOT_INTERFACE_H_

/* LEJOS NXJ I/O drivers */
#include "mytypes.h"
#include "interrupts.h"
#include "aic.h"
#include "AT91SAM7.h"
#include "uart.h"
#include "systick.h"
#include "nxt_avr.h"
#include "twi.h"
#include "platform_hooks.h"
#include "nxt_lcd.h"
#include "nxt_motors.h"
#include "sensors.h"
#include "display.h"
#include "i2c.h"
#include "bt.h"
#include "sound.h"
#include "udp.h"

#include "ecrobot_types.h"
#include "ecrobot_bluetooth.h"
#include "ecrobot_usb.h"

typedef enum {
	NXT_PORT_A,
	NXT_PORT_B,
	NXT_PORT_C
}MOTOR_PORT_T;

typedef enum {
	NXT_PORT_S1,
	NXT_PORT_S2,
	NXT_PORT_S3,
	NXT_PORT_S4
}SENSOR_PORT_T;

typedef enum {
	EXECUTED_FROM_FLASH,
	EXECUTED_FROM_SRAM,
	DEVICE_NO_INIT,
	DEVICE_INITIALIZED,
	BT_NO_INIT,
	BT_INITIALIZED,
	BT_CONNECTED,
	BT_STREAM,
}SYSTEM_T;

#define EXTERNAL_WAV_DATA(name) \
  extern const CHAR name##_wav_start[]; \
  extern const CHAR name##_wav_end[]; \
  extern const CHAR name##_wav_size[]

#define WAV_DATA_START(name) name##_wav_start
#define WAV_DATA_END(name)   name##_wav_end
#define WAV_DATA_SIZE(name)  name##_wav_size

#define EXTERNAL_BMP_DATA(name) \
  extern const CHAR name##_bmp_start[]; \
  extern const CHAR name##_bmp_end[]; \
  extern const CHAR name##_bmp_size[]

#define BMP_DATA_START(name) name##_bmp_start
#define BMP_DATA_END(name)   name##_bmp_end
#define BMP_DATA_SIZE(name)  name##_bmp_size

#define LOWSPEED_9V 1
#define LOWSPEED    2


/* NXT servo motor API */
extern  S32 ecrobot_get_motor_rev(U8 port_id);
extern void ecrobot_set_motor_rev(U8 port_id, S32 rev);
extern void ecrobot_set_motor_speed(U8 port_id, S8 speed);
extern void ecrobot_set_motor_mode_speed(U8 port_id, S32 mode, S8 speed);

/* NXT light sensor API */
extern  U16 ecrobot_get_light_sensor(U8 port_id);
extern void ecrobot_set_light_sensor_active(U8 port_id);
extern void ecrobot_set_light_sensor_inactive(U8 port_id);

/* NXT touch sensor API */
extern   U8 ecrobot_get_touch_sensor(U8 port_id);

/* NXT sound sensor API */
extern  U16 ecrobot_get_sound_sensor(U8 port_id);

/* NXT I2C API */
extern void ecrobot_init_i2c(U8 port_id, U8 type);
extern   U8 ecrobot_wait_i2c_ready(U8 port_id, U32 wait);
extern SINT ecrobot_send_i2c(U8 port_id, U32 address, SINT i2c_reg, U8 *buf, U32 len);
extern SINT ecrobot_read_i2c(U8 port_id, U32 address, SINT i2c_reg, U8 *buf, U32 len);
extern void ecrobot_term_i2c(U8 port_id);

/* NXT ultrasonic sensor API */
extern void ecrobot_init_sonar_sensor(U8 port_id);
extern  S32 ecrobot_get_sonar_sensor(U8 port_id);
extern void ecrobot_term_sonar_sensor(U8 port_id);

/* HiTechnic gyro sensor API */
extern  U16 ecrobot_get_gyro_sensor(U8 port_id);

/* HiTechnic acceleration sensor API */
extern void ecrobot_init_accel_sensor(U8 port_id);
extern void ecrobot_get_accel_sensor(U8 port_id, S16 buf[3]);
extern void ecrobot_term_accel_sensor(U8 port_id);

/* HiTechnic IR Seeker API */
extern void ecrobot_init_ir_seeker(U8 port_id);
extern void ecrobot_get_ir_seeker(U8 port_id, S8 buf[6]);
extern void ecrobot_term_ir_seeker(U8 port_id);

/* HiTechnic color sensor API */
extern void ecrobot_init_color_sensor(U8 port_id);
extern void ecrobot_get_color_sensor(U8 port_id, S16 buf[3]);
extern void ecrobot_term_color_sensor(U8 port_id);

/* HiTechnic compass sensor API */
extern void ecrobot_init_compass_sensor(U8 port_id);
extern   U8 ecrobot_cal_compass_sensor(U8 port_id);
extern  S16 ecrobot_get_compass_sensor(U8 port_id);
extern void ecrobot_term_compass_sensor(U8 port_id);

/* RCX sensors API */
extern void ecrobot_set_RCX_power_source(U8 port_id);
extern void ecrobot_term_RCX_power_source(U8 port_id);
extern  S16 ecrobot_get_RCX_sensor(U8 port_id);
extern   U8 ecrobot_get_RCX_touch_sensor(U8 port_id);

/* NXT internal status API */
extern  U16 ecrobot_get_battery_voltage(void);
extern  U32 ecrobot_get_systick_ms(void);
extern   U8 ecrobot_is_ENTER_button_pressed(void);
extern   U8 ecrobot_is_RUN_button_pressed(void);

/* LCD display command for system */
extern SINT ecrobot_bmp2lcd(const CHAR *file, U8 *lcd, S32 width, S32 height);
extern void ecrobot_show_int(S32 var);
extern void ecrobot_debug1(UINT var1, UINT var2, UINT var3);
extern void ecrobot_debug2(UINT var1, UINT var2, UINT var3);
extern void ecrobot_status_monitor(const CHAR *target_name);
extern void ecrobot_adc_data_monitor(const CHAR *target_name);
extern void ecrobot_bt_data_logger(S8 data1, S8 data2);
extern void ecrobot_bt_adc_data_logger(S8 data1, S8 data2, S16 adc1, S16 adc2, S16 adc3, S16 adc4);

/* NXT sound API */
extern SINT ecrobot_sound_tone(U32 freq, U32 ms, U32 vol);
extern SINT ecrobot_sound_wav(const CHAR *file, U32 length, S32 freq, U32 vol);

/* system hook functions */
extern void ecrobot_device_initialize(void);
extern void ecrobot_device_terminate(void);

extern void user_1ms_isr_type2(void); /* This function must be used for only TOPPERS/ATK */
extern void check_NXT_buttons(void);  /* This function must be used for only TOPPERS/JSP */
extern SINT get_OS_flag(void);        /* This function must be used for only TOPPERS/JSP */

#endif
