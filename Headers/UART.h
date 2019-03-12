/*
 * UART.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"

#define UART0_BAUD_RATE 38400
extern uint8_t global_data;
extern uint8_t global_flag;

void UART0_init(void);
uint8_t UART0_receive(void);
void UART0_send(uint8_t ch);
void UART0_disable(void);
void UART0_Task_Recive(void);

#endif /* UART_H_ */
