/*
 * Task.c
 *
 * Created: 2/23/2019 2:39:35 PM
 *  Author: AVE-LAP-040
 */ 

/*We Include Leds Module in App*/
#include <stdint.h>
#include "Schedular.h"
#include "Task.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

/*Task 1*/	
void Task1()
{
	/*Toggle The Led 1*/
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
}
/*Task2*/
void Task2()
{
	/*Toggle The Led 2*/
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
}
/*Task3*/
void Task3()
{
	/*Toggle The Led 3*/
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
}
/*Task 4*/
void Task4()
{
	/*Toggle The Led 4*/
}

void Task5()
{
    /*Empty Task*/
}


