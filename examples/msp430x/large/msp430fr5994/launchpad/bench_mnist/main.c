#include <stdint.h>

#include "msp430.h"
#include "tpl_os.h"

#include "include/mnist.h"
#include "include/input.h"

#include <math.h>

#define MIN_ADAPT_THRESH 0

/* 
    skipRows / skipColumns / skipClass are in REHASH but here win don't need them 
    So there are at 0 and remain at 0 all the time (ie, no skip)
*/
#define APP_Task_task_init_START_SEC_VAR_FRAM_UP_8BIT
#include "tpl_memmap.h"

VAR(uint8_t, AUTOMATIC) skipRows = MIN_ADAPT_THRESH;
VAR(uint8_t, AUTOMATIC) skipColumns = MIN_ADAPT_THRESH;
VAR(uint8_t, AUTOMATIC) skipClass = MIN_ADAPT_THRESH;

#define APP_Task_task_init_STOP_SEC_VAR_FRAM_UP_8BIT
#include "tpl_memmap.h"

#define APP_Task_task_init_START_SEC_VAR_FRAM_UP_16BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) neuronNum = 0;
VAR(int, AUTOMATIC) rowNum = 0;
VAR(int, AUTOMATIC) prediction = 0;
VAR(int, AUTOMATIC) softmaxSumItr = 0;
#define APP_Task_task_init_STOP_SEC_VAR_FRAM_UP_16BIT
#include "tpl_memmap.h"

#define APP_Task_task_init_START_SEC_VAR_FRAM_UP_32BIT
#include "tpl_memmap.h"
VAR(float, AUTOMATIC) activations[MNIST_LABELS];
VAR(float, AUTOMATIC) max_activation;
VAR(float, AUTOMATIC) softmaxMax;
VAR(float, AUTOMATIC) softmaxSum;
#define APP_Task_task_init_STOP_SEC_VAR_FRAM_UP_32BIT
#include "tpl_memmap.h"


#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void){


	// Disable the GPIO power-on default high-impedance mode
	// to activate previously configured port settings
	PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= BIT0;
    P1OUT &= ~BIT0;
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_init_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_init)
{


    neuronNum = 1;
    // rowNum = skipRows;
    prediction = 0;
    max_activation = 0;
    softmaxMax = 0;
    softmaxSum = 0;
    softmaxSumItr = 0;

    activations[0] = b[0];
    ChainTask(task_neural_network_hypothesis);
}

#define APP_Task_task_init_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_neural_network_hypothesis_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_neural_network_hypothesis)
{
    int i = neuronNum;
    int j = rowNum;
    int k = skipColumns;
    int skip_columns = skipColumns;
    float tempActivations = activations[i];

    for (; k < MNIST_IMAGE_WIDTH - skip_columns; k++)
    {

        tempActivations += W[i][j][k] * PIXEL_SCALE(number_pixels[j][k]);
    }

    activations[i] = tempActivations;

    if (j < (MNIST_IMAGE_HEIGHT - skipRows) - 1)
    {
        rowNum = ++j;

        ChainTask(task_neural_network_hypothesis);
    }
    if (i < (MNIST_LABELS - skipClass) - 1)
    {
        neuronNum = ++i;
        rowNum = skipRows;
        activations[i] = b[i];
        ChainTask(task_neural_network_hypothesis);
    }
    else
        ChainTask(task_neural_network_softmax_max);
}
#define APP_Task_task_neural_network_hypothesis_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_neural_network_softmax_max_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_neural_network_softmax_max)
{

    int i;
    float max;

    for (i = 1, max = activations[0]; i < (MNIST_LABELS - skipClass);
            i++)
    {
        if (activations[i]> max)
        {
            max = activations[i];
        }
    }

    softmaxMax = max;

    ChainTask(task_neural_network_softmax_sum);
}
#define APP_Task_task_neural_network_softmax_max_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_neural_network_softmax_sum_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_neural_network_softmax_sum)
{
    int i = softmaxSumItr;
    float max = softmaxMax;
    float sum = softmaxSum;

    activations[i] = exp(activations[i] - max);
    // activations[i] = activations[i] - max;

    sum += activations[i];

    softmaxSum = sum;

    if (i < (MNIST_LABELS - skipClass) - 1)
    {
        softmaxSumItr = ++i;
        ChainTask(task_neural_network_softmax_sum);
    }
    else
        ChainTask(task_neural_network_softmax);
}
#define APP_Task_task_neural_network_softmax_sum_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_neural_network_softmax_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_neural_network_softmax)
{
    int i;
    float sum = softmaxSum;

    for (i = 0; i < (MNIST_LABELS - skipClass); i++)
    {
        activations[i] = activations[i] / sum;
    }

    ChainTask(task_classify);
}
#define APP_Task_task_neural_network_softmax_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_classify_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_classify)
{
    int predict = 0;
    int i = 0;

    max_activation = activations[0];

    for (i = 0; i < (MNIST_LABELS - skipClass); i++)
    {
        if (max_activation < activations[i])
        {
            max_activation = activations[i];
            predict = i;
        }
    }

    prediction = predict;

    P1OUT |= BIT0;
    TerminateTask();
}
#define APP_Task_task_classify_STOP_SEC_CODE
#include "tpl_memmap.h"
