#include "tpl_os.h"
#include "vp_ipc_devices.h"
#include "tpl_machine.h"
#include <math.h>

#include <stdio.h>

#include "../viper2/device/tpl_can_driver.h"

/* Variables Initialisation */
#define BETA_INIT 0.000000001
#define TICK_PER_ROTATION 100 // TODO : Find a way to synchronize viper2 and trampoline about TICK_PER_ROTATION
#define PI 3.141592
#define RADIUS 3
int gap = 10;
double theta = 1.570796;
double position[2] = {100,100};
double position_old[2] = {100,90};
double tickincm = 2*PI*RADIUS/TICK_PER_ROTATION; /* conversion tick -> centimeter (1 tick = perimeter / TOTAL_TICK ~ 18.8 / 100 ~ 0.188cm */
char MoveVector[2] = {0,0};
tpl_receiving_ipdu r_ipdu;
double beta;
double r;

/* Task declaration */
DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareTask(Idle);
DeclareTask(Sensor);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL2] Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL2] Au revoir et a bientot :)\n");
}

TASK(Idle)
{	
	printf("[TPL2] Idle\n");
	TerminateTask();
}


TASK(Sensor)
{
    /* TODO : Do a loop in that task or a ChainTask to herself (like it's done) ? */
    
    /* Wait until the two sensors are received by Trampoline*/
    WaitEvent(Event1);
    WaitEvent(Event2);
    ClearEvent(Event1);
    ClearEvent(Event2);
    
    int sensor1 = (int)vp_ipc_read_reg(&viper, MOTOR2_1 | MOTOR2_1_SENSOR);
    int sensor2 = (int)vp_ipc_read_reg(&viper, MOTOR2_2 | MOTOR2_2_SENSOR);
    
    /* Convert ticks in centimeters */
    double m1 = (double)(sensor1*tickincm);
    double m2 = (double)(sensor2*tickincm);
    
    /* Find Beta : delta angle due to new sensor values */
    beta = (m1 - m2)/gap;
    
    /* If beta is equal to zero, move the robot straight ahead, in the same direction as the last movement 
     otherwise, calculate the new position according to the delta of the two motor tick numbers. */
    if ((beta < BETA_INIT) && ((beta*(-1)) < BETA_INIT))
    {
        //printf("[TPL1] Beta equals zero \n");
        
        if ( (sensor1 != 0) && (sensor2 != 0) )
        {
            /* Find last movement (dx and dy) */
            double dx = position[0] - position_old[0];
            double dy = position[1] - position_old[1];
            /* Find distance done during the last movement (by knowing hypotenuse) */            
            double hyp = sqrt(dx*dx + dy*dy);
            
            /* Store actual position in old position */
            position_old[0] = position[0];
            position_old[1] = position[1];
            
            /* Move the robot lower or faster according to the sensors */
            position[0] += m1*dx/hyp;
            position[1] += m2*dy/hyp;        
            
            //printf("[TPL1] Straigh ahead - dx:%f dy:%f hyp:%f m1:%f dx':%f dy':%f\n",dx,dy,hyp,m1,(m1*dx/hyp),(m2*dy/hyp));
        }
    }    
    else
    {
        /* Store actual position in old position */
        position_old[0] = position[0];
        position_old[1] = position[1];
        
        /* Find radius to the circle the robot is moving on */
        r = (m1 + m2)/(2*beta);
        
        /* Find coordinates of the circle's center (the robot is moving on) */
        double x0 = position[0] - r*sin(theta);
        double y0 = position[1] + r*cos(theta);
        /* Increment angle adding delta angle */
        theta += beta;
        /* Find next position */
        position[0] = x0 + r*sin(theta);
        position[1] = y0 - r*cos(theta);
        
        //printf("[TPL1] Robot's position - m1:%f m2:%f beta:%f r:%f x0:%f y0:%f theta:%f x:%f y:%f\n",m1,m2,beta,r,x0,y0,theta,position[0],position[1]);
    }
    
    /* Write in the screen registers*/
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG0, (reg_t)(position[0]));
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG1, (reg_t)(position[1]));
    vp_ipc_signal_update(&viper, LCD2, LCD2_REG0 | LCD2_REG1);
    
    ChainTask(Sensor);    
}

ISR(IsrSensor1)
{
    SetEvent(Sensor, Event1);
}

ISR(IsrSensor2)
{
    SetEvent(Sensor, Event2);
}

ISR(CAN) 
{
    /* variables */
    unsigned char my_buf[8];
    r_ipdu.buf = my_buf;
    
    /* received ipdu */
    receive_ipdu(&viper, CAN2, &r_ipdu);
    printf("[TPL2] Received IPDU\n");
    printf("[TPL2] Received an I-PDU... id = %d - mode = %d - buf = %d-%d\n",r_ipdu.id,r_ipdu.transmission_mode,r_ipdu.buf[0],r_ipdu.buf[1]);
    
    /* Change Motor : TODO : Only one update !*/
    vp_ipc_write_reg(&viper, MOTOR2_1_MOTOR2_1_CONTROL, (reg_t)r_ipdu.buf[0]);
    vp_ipc_signal_update(&viper, MOTOR2_1, MOTOR2_1_CONTROL);
    
    vp_ipc_write_reg(&viper, MOTOR2_2_MOTOR2_2_CONTROL, (reg_t)r_ipdu.buf[1]);
    vp_ipc_signal_update(&viper, MOTOR2_2, MOTOR2_2_CONTROL);
    
}