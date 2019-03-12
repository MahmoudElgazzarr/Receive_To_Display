/*
 * delay_Timer.h
 *
 * Created: 2/14/2019 10:07:03 AM
 *  Author: AVE-LAP-040
 */ 


#ifndef DELAY_TIMER_H_
#define DELAY_TIMER_H_

#include <stdint.h>

extern volatile uint8_t Sec;

#define OS_TICK_INTERVAL_MSEC 1

void timer_init(void);
void timer_delay(uint32_t n);
void set_Callback_Function(void (*ptr)(void));

#define SFIOR (*(volatile uint8_t*)0x50)
#define TCCR1A (*(volatile uint8_t*)0x4F)
#define TCNT0 (*(volatile uint8_t*)0x52)
#define OCR0 (*(volatile uint8_t*)0x5C)
#define TIMSK (*(volatile uint8_t*)0x59)
#define TIFR (*(volatile uint8_t*)0x58)
#define SREG (*(volatile uint8_t*)0x5F)
#define TCCR0 (*(volatile uint8_t*)0x53)

#define IBIT 7
#define TOIE0 0

#define OCF0 1

#define CS00 0
#define CS01 1
#define CS02 2

#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7
#define OCIE0 1

#define ZERO 0
#endif /* DELAY_TIMER_H_ */
