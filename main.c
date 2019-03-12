

/**
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "Task.h"
#include "Schedular.h"


uint32_t count = 0;

#define FIVE_HUNDRED_OS_TICKS 500
#define ONE_OS_TICK 1

int main(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

      //
      // Check if the peripheral access is enabled.
      //
      while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
      {}

      //
      // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
      // enable the GPIO pin for digital function.
      //
      GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
      GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
      GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

      /*Start Schedulart*/
      scheduler_Init();

      /*Add Four Tasks*/
      scheduler_Add_Task(Task1,1000,priority_1,ID_0);
      scheduler_Add_Task(Task2,2000,priority_1,ID_1);
      scheduler_Add_Task(Task3,3000,priority_1,ID_2);
      scheduler_Add_Task(Task4,4000,priority_1,ID_3);

      /*Task To Remove Tasks*/
      scheduler_Add_Task(Task5,5000,priority_1,ID_4);

      /* Start Schedular */
      scheduler_Start(ONE_OS_TICK);
    while(1)
    {

    }

}
