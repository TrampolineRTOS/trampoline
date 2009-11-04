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
double position[2] = {100,50};
double position_old[2] = {100,40};
double tickincm = 2*PI*RADIUS/TICK_PER_ROTATION; /* conversion tick -> centimeter (1 tick = perimeter / TOTAL_TICK ~ 18.8 / 100 ~ 0.188cm */
char MoveVector[2] = {0,0};
tpl_receiving_ipdu r_ipdu;
double beta;
double r;

int sensor1 = 0;
int sensor2 = 0;

// TODO : Find a way to synchronize viper2 and trampoline about TICK_PER_ROTATION
/* Variable from Timer.Viper2 */
double delayBetweenTwoMesures = 0.2;
/* Variable from Viper2.Motor */
unsigned char max_pwm = 100;
unsigned char secondesperminute = 60;
unsigned char tickperrotation = 100;
unsigned int max_rpm = 300;

/* Task declaration */
DeclareTask(Sensors);
DeclareTask(MotorControl);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL3] Starting !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL3] Ending !\n");
}

TASK(Sensors)
{
    int temp1 = (int)vp_ipc_read_reg(&viper, MOTOR3_1 | MOTOR3_1_SENSOR);
    int temp2 = (int)vp_ipc_read_reg(&viper, MOTOR3_2 | MOTOR3_2_SENSOR);
    
    /* Convert ticks in centimeters */
    double m1 = (double)((temp1-sensor1)*tickincm);
    double m2 = (double)((temp2-sensor2)*tickincm);
    
    sensor1 = temp1;
    sensor2 = temp2; 
    
    /* Find Beta : delta angle due to new sensor values */
    beta = (m1 - m2)/gap;
    
    /* If beta is equal to zero, move the robot straight ahead, in the same direction as the last movement 
     otherwise, calculate the new position according to the delta of the two motor tick numbers. */
    if ((beta < BETA_INIT) && ((beta*(-1)) < BETA_INIT))
    {
        //printf("[TPL1] Beta equals zero \n");
        
        if ( (m1 != 0) && (m2 != 0) )
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
    vp_ipc_write_reg(&viper, LCD3_LCD3_REG0, (reg_t)(position[0]));
    vp_ipc_write_reg(&viper, LCD3_LCD3_REG1, (reg_t)(position[1]));
    vp_ipc_signal_update(&viper, LCD3, LCD3_REG0 | LCD3_REG1);
    
    TerminateTask();
    
}

TASK(MotorControl){
    
    /* variables */
    unsigned char my_buf[8];
    r_ipdu.buf = my_buf;
    
    /* received ipdu */
    receive_ipdu(&viper, NET3, &r_ipdu);
    printf("[TPL3] Received an I-PDU... id = %d - mode = %d - buf = %d-%d\n",r_ipdu.id,r_ipdu.transmission_mode,r_ipdu.buf[0],r_ipdu.buf[1]);
    
    /* Receiving robot1 ticks -> find motor commands */
    // TODO : receiving dx and dy (of the robot1), find motor commands
    double pwm1 = r_ipdu.buf[0] * max_pwm * secondesperminute / (tickperrotation * delayBetweenTwoMesures * max_rpm);
    double pwm2 = r_ipdu.buf[1] * max_pwm * secondesperminute / (tickperrotation * delayBetweenTwoMesures * max_rpm);
    
    /* Change Motor */
    vp_ipc_write_reg(&viper, MOTOR3_1_MOTOR3_1_CONTROL, (reg_t)pwm1);
    vp_ipc_write_reg(&viper, MOTOR3_2_MOTOR3_2_CONTROL, (reg_t)pwm2);
    
    vp_ipc_signal_update(&viper, MOTOR3_1, MOTOR3_1_CONTROL);
    vp_ipc_signal_update(&viper, MOTOR3_2, MOTOR3_2_CONTROL);
    
    TerminateTask();
}

ISR(Network) 
{
    ActivateTask(MotorControl);
}
