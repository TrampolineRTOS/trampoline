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
#define RADIUS 30
int gap = 10;
double theta = 1.570796;
double position[2] = {100,150};
double position_old[2] = {100,140};
double tickincm = 2*PI*RADIUS/TICK_PER_ROTATION; /* conversion tick -> centimeter (1 tick = perimeter / TOTAL_TICK ~ 188 / 100 ~ 1.88cm */
char MoveVector[2] = {0,0};
tpl_sending_ipdu s_ipdu;
tpl_receiving_ipdu r_ipdu;
double beta;
double r;

int sensor1 = 0;
int sensor2 = 0;

/* Task declaration */
DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareTask(MotorControl);
DeclareTask(SensorAndSendVector);
DeclareResource(ResourceVector);

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL1] Ca demarre !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL1] Au revoir et a bientot :)\n");
}

TASK(MotorControl)
{
    /* variables */
    unsigned char my_buf[8];
    r_ipdu.buf = my_buf;
    
    /* received ipdu */
    receive_ipdu(&viper, CAN1_1, &r_ipdu);
    printf("[TPL1] Received IPDU\n");
    printf("[TPL1] Received an I-PDU... id = %d - mode = %d - buf = %d\n",r_ipdu.id,r_ipdu.transmission_mode,r_ipdu.buf[0]);
    
    /* Receiving movement vector, find motor commands */
    //TODO : keep the same radius circle !!!
    switch(r_ipdu.buf[0])
    {
        case 1:
        {
            MoveVector[0] += 1;
            MoveVector[1] += 1;
            break;
        }
        case 2:
        {
            if (MoveVector[0] != 0)
            {
                MoveVector[0] -= 1;
            }
            if (MoveVector[1] != 0)
            {
                MoveVector[1] -= 1;
            }
            break;
        }
        case 3:
        {
            MoveVector[0] += 1;
            break;
        }
        case 4:
        {
            MoveVector[1] += 1;
            break;
        }
        default:
        {
            break;
        }
    }

    printf("[TPL1] MoveVector[0]:%d MoveVector[1]:%d\n",MoveVector[0],MoveVector[1]);
    /* Change Motor */
    //TODO : Only one update ? 
    vp_ipc_write_reg(&viper, MOTOR1_1_MOTOR1_1_CONTROL, (reg_t)MoveVector[0]);
    vp_ipc_write_reg(&viper, MOTOR1_2_MOTOR1_2_CONTROL, (reg_t)MoveVector[1]);
    
    vp_ipc_signal_update(&viper, MOTOR1_1, MOTOR1_1_CONTROL);
    vp_ipc_signal_update(&viper, MOTOR1_2, MOTOR1_2_CONTROL);
    
	TerminateTask();
}

TASK(SensorAndSendVector)
{
    
    int temp1 = (int)vp_ipc_read_reg(&viper, MOTOR1_1 | MOTOR1_1_SENSOR);
    int temp2 = (int)vp_ipc_read_reg(&viper, MOTOR1_2 | MOTOR1_2_SENSOR);
    printf("[TPL1] - sensor1:%d - sensor2:%d\n",sensor1,sensor2);
    printf("[TPL1] --> m1:%d - m2:%d\n",temp1-sensor1,temp2-sensor2);

    /* Convert ticks in centimeters */
    double m1 = (double)((temp1-sensor1)*tickincm);
    double m2 = (double)((temp2-sensor2)*tickincm);

    sensor1 = temp1;
    sensor2 = temp2;

    double dx = 0;
    double dy = 0;

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
            dx = position[0] - position_old[0];
            dy = position[1] - position_old[1];
            /* Find distance done during the last movement (by knowing hypotenuse) */            
            double hyp = sqrt(dx*dx + dy*dy);
            
            /* Store actual position in old position */
            position_old[0] = position[0];
            position_old[1] = position[1];
            
            /* Move the robot lower or faster according to the sensors */
            position[0] += m1*dx/hyp;
            position[1] += m2*dy/hyp;        
            
            printf("hyp:%f m1:%f m2:%f dx:%f dy:%f \n",hyp,m1,m2,dx,dy);
            //printf("[TPL1] Straigh ahead - dx:%f dy:%f hyp:%f m1:%f dx':%f dy':%f\n",dx,dy,hyp,m1,(m1*dx/hyp),(m2*dy/hyp));
        }
    }    
    else
    {
        /* Find last movement (dx and dy) */
        dx = position[0] - position_old[0];
        dy = position[1] - position_old[1];
        
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
        printf("r:%f theta:%f x0:%f y0:%f \n",r,theta,x0,y0);
        //printf("[TPL1] Robot's position - m1:%f m2:%f beta:%f r:%f x0:%f y0:%f theta:%f x:%f y:%f\n",m1,m2,beta,r,x0,y0,theta,position[0],position[1]);
    }
        
    
    /* SendVector to CAN */
    s_ipdu.id = 1;
    s_ipdu.transmission_mode = 0;
    s_ipdu.nb_message = 2;
    
    unsigned char test[2]; // = "message";
    
    // ##########################
    // dx and dy can be negative !!!
    
    test[0] = dx;
    test[1] = dy;
    s_ipdu.buf = test;
    
    printf("[TPL1] Send an I-PDU... id:%d - mode:%d - buf:%d-%d\n", s_ipdu.id,s_ipdu.transmission_mode,s_ipdu.buf[0],s_ipdu.buf[1]);
    send_ipdu(&viper, CAN1_2, &s_ipdu);
    
    printf("[TPL1] position[0]:%f position[1]:%f\n",position[0],position[1]);
    /* Write in the screen registers*/
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG0, (reg_t)(position[0]));
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG1, (reg_t)(position[1]));
    vp_ipc_signal_update(&viper, LCD1, LCD1_REG0 | LCD1_REG1);

    TerminateTask();
    
}

ISR(CAN) 
{
    ActivateTask(MotorControl);        
}
