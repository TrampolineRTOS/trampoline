#ifndef _SENSORS_H
#  define _SENSORS_H

typedef struct {
  char type;
  char mode;
  short raw;
  short value;
  char boolean;
} sensor_t;


#  define N_SENSORS (4)

extern sensor_t sensors[N_SENSORS];
extern void init_sensors(void);
extern void poll_sensors(void);
extern void read_buttons(int, short *);
extern void check_for_data(char *valid, char **nextbyte);
extern void set_digi0(int);
extern void unset_digi0(int);
extern void set_digi1(int);
extern void unset_digi1(int);

#endif // _SENSORS_H
