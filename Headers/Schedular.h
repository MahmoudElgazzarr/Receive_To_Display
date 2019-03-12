/*
 * Shedular.h
 *
 * Created: 2/23/2019 2:16:44 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef SHEDULAR_H_
#define SHEDULAR_H_

#include <stdint.h>

/*Defines Os Tick Interval*/
#define OS_TICK_INTERVAL_MSEC 1

/*Defines NUmber Of Tasks*/
#define NUM_TASKS 5

/*defines Maxmium Number of Tasks*/
#define MAX_NUM_TASKS 9

#define TRUE 1
#define FALSE 0

/*struct For The Tasks*/
typedef struct Tasks_Struct
{
    /*Pointer To void void Function*/
    void (*Tasks_Ptr)(void);
    /*Task_Periodicity*/
    uint32_t Task_Periodicity;
    /*Remaining_Ticks For The Task To Be Excuted*/
    uint32_t Remaining_Ticks;
    /*Priority OF Task*/
    uint32_t Task_Priority;
    /*uint8_t ID Of the Task*/
    uint8_t ID;
}Tasks_T;


#define ZERO 0
#define ONE 1

#define TRUE 1
#define FALSE 0

/*Enum for Task IDS*/
enum ID
{
    ID_0,
    ID_1,
    ID_2,
    ID_3,
    ID_4,
    ID_5,
    };

/*Enum For Priority*/

enum priority
{
    priority_1,
    priority_2,
    priority_3,
    priority_4,
    priority_5,
    priority_6,
};

/*Difiniton For The Tasks*/
uint8_t scheduler_Add_Task(void (*Task)(void),uint32_t Periodicity,uint8_t priority,uint8_t ID);
void scheduler_Remove_Task(uint8_t ID);
void scheduler_Init();
/*SysTick Handler For Scheduler*/
void SysTickIntHandler();

void scheduler_Start(uint16_t Tick);
void dispatcher(void);
void static set_flag(void);
void static Swap_Tasks(uint8_t indexx);

#define NULL ((void *)0)
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10

#endif /* SHEDULAR_H_ */
