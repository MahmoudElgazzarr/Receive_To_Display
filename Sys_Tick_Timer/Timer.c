/*
 * delay_Timer.c
 *
 * Created: 2/14/2019 10:06:23 AM
 *  Author: AVE-LAP-040
 */ 

#include "Timer.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"


void (*Pointer_To_Func)(void);



/*Global Setting To Set Timer For 1 MSec on 16 MHZ Crystal*/
void timer_init()
{
	/*Enable Global Interrupt*/
	IntMasterEnable();
	/*Enable Systick_Timer*/
	SysTickIntEnable();
	/*Set Period For 1 MSEC*/
	SysTickPeriodSet(16000UL);
	/*Enable Systick Timer*/
	SysTickEnable();
}

void set_Callback_Function(void (*SysTickIntHandler)(void))
{
	/*Set Callback Function*/
	SysTickIntRegister(SysTickIntHandler);
}
