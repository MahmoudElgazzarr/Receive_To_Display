/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:16:23 PM
 *  Author: AVE-LAP-040
 */ 



#include <stdint.h>
#include "Timer.h"
#include "Schedular.h"
#include "Task.h"


/*Global Variable To Set Timer For How Many Ticks*/
volatile static uint16_t Tick;

volatile uint16_t OS_Tick_in_Timer;

/*Flag To Be Set In The ISR When Happens*/

volatile uint8_t flag = ZERO;

/*Variable To Point To the last Element In the array Of Tasks*/
static volatile uint8_t Last;


/*Create Array of Structure To the Tasks*/

Tasks_T Tasks_Arr[MAX_NUM_TASKS];

/*Static uin8 sta*/

void scheduler_Init()
{
    uint32_t i;
    /*Inialize array of structure With Zero*/
    for(i=ZERO;i<NUM_TASKS;i++)
    {
        Tasks_Arr[i].Tasks_Ptr = NULL;
        Tasks_Arr[i].Task_Priority =ZERO;
        Tasks_Arr[i].Task_Periodicity = ZERO;
        Tasks_Arr[i].Task_Priority = ZERO;
        Tasks_Arr[i].ID = ZERO;
    }
}
/*Start Schedular With initalized Os Tick and Set Callback Function in Timer*/
void scheduler_Start(uint16_t OS_Tick)
{
    /*Set_OS_Tick*/
    OS_Tick_in_Timer = OS_Tick;
    /*Set Call_Back_function To The Set Flag*/
    set_Callback_Function(set_flag);
    /*Inialize Timer*/
    timer_init();
    while(1)
    {
        dispatcher();
    }
}
void static set_flag(void)
{
    if( flag == ZERO)
    {
        flag = ONE;
    }
}
uint8_t scheduler_Add_Task(void (*Task)(void),uint32_t Periodicity,uint8_t priority,uint8_t ID)
{

    /*Index Parmater*/
    uint8_t index,indexx;
    /*If Num of Tasks is Larger Than Max Number Of Tasks return False*/
    if( NUM_TASKS >= MAX_NUM_TASKS )
    {
        return FALSE;
    }
    /*Else set pointer of Function into the Structure
        Set Remaining Ticks With Periodicity
        Increment Last Element of Array Of structure
    */
    else
    {
    Tasks_Arr[Last].Tasks_Ptr = Task;
    Tasks_Arr[Last].Task_Periodicity = Periodicity;
    Tasks_Arr[Last].Remaining_Ticks = Periodicity;
    Tasks_Arr[Last].ID = ID;
    Last++;
    /*Sort The Array From Low To High Depend on Priority*/

    for(index = ZERO; index < NUM_TASKS;index++)
    {
        for (indexx = ZERO; indexx < NUM_TASKS - ONE;indexx++)
        {
            /*if priority is Inverted*/
            if ( Tasks_Arr[indexx].Task_Priority < Tasks_Arr[indexx + ONE].Task_Priority )
            {
                /*Swap Two Tasks*/
                Swap_Tasks(indexx);
            }
        }
    }
    return TRUE;
    }
}

void scheduler_Remove_Task(uint8_t ID)
{
    uint8_t index;
    for (index = 0; index < NUM_TASKS; index++)
    {
        if (Tasks_Arr[index].ID == ID)
        {
            /*if the Priority is 99 the task will not Excute*/
            Tasks_Arr[index].Task_Priority = 99;
        }
    }
}

void static Swap_Tasks(uint8_t indexx)
{
    /*Create Temp Structure*/
    Tasks_T Swap_Structure;
    /*Save Tasks_Array[indexx]*/
    Swap_Structure.Task_Priority = Tasks_Arr[indexx].Task_Priority;
    Swap_Structure.Task_Periodicity = Tasks_Arr[indexx].Task_Periodicity;
    Swap_Structure.Remaining_Ticks = Tasks_Arr[indexx].Remaining_Ticks;
    Swap_Structure.Tasks_Ptr = Tasks_Arr[indexx].Tasks_Ptr;
    Swap_Structure.ID = Tasks_Arr[indexx].ID;

    /* Swap Tasks*/
    Tasks_Arr[indexx].Remaining_Ticks = Tasks_Arr[indexx + 1].Remaining_Ticks;
    Tasks_Arr[indexx].Task_Priority = Tasks_Arr[indexx + 1].Task_Priority;
    Tasks_Arr[indexx].Task_Periodicity = Tasks_Arr[indexx + 1].Task_Periodicity;
    Tasks_Arr[indexx].Tasks_Ptr = Tasks_Arr[indexx+1].Tasks_Ptr;
    Tasks_Arr[indexx].ID = Tasks_Arr[indexx+1].ID;

    /*Swap Tasks_Arr[indexx+1]*/
    Tasks_Arr[indexx + 1].Remaining_Ticks = Swap_Structure.Remaining_Ticks;
    Tasks_Arr[indexx + 1].Task_Priority = Swap_Structure.Task_Priority;
    Tasks_Arr[indexx + 1].Task_Periodicity = Swap_Structure.Task_Periodicity;
    Tasks_Arr[indexx + 1].Tasks_Ptr = Swap_Structure.Tasks_Ptr;
    Tasks_Arr[indexx + 1].ID = Swap_Structure.ID;
}

void dispatcher(void)
{
    volatile static uint8_t NewTickFlag = ZERO ;
    uint32_t j;
    /*IF Timer Interrupt Happened Flag Will Be One*/
    if (ONE == flag)
    {
        /* Increment Flag */
        NewTickFlag++;
    /*For Loop For The Tasks and Scheduale Them*/
    for(j=ZERO;j<NUM_TASKS;j++)
    {
        /*Decrement Periodicity by ONE Every Tick */
        Tasks_Arr[j].Remaining_Ticks--;
        /*IF Remaining  Ticks Equals Zero Excute Task and Set Remaining To The Periodicity*/
        if(Tasks_Arr[j].Remaining_Ticks == ZERO && Tasks_Arr[j].Task_Priority != 99 )
        {
            /*Call Function*/
            Tasks_Arr[j].Tasks_Ptr();
            /*Set Remaining To The Periodicity*/
            Tasks_Arr[j].Remaining_Ticks = Tasks_Arr[j].Task_Periodicity;
        }
    }
    /*Set Flag To Zero*/
        flag = ZERO;
    }
}
void SysTickIntHandler()
{
    Tick++;
    if (OS_Tick_in_Timer == Tick)
    {
        /*Call Back Function*/
        set_flag();
        /*Set Tick To Zero*/
        Tick = ZERO;
    }
}
