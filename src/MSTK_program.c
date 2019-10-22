
#include "LSTD_TYPES.h"
#include "MSTK_private.h"
#include "MSTK_interface.h"


void (* MSTK_CallBack)(void);    //pointer to function 

void SysTick_Handler(void)// interrupt void and return void because it executed by hardware and hardware doesnt take any thing
{
	
	MSTK_CallBack();
}
//take care if there is an interrupt fired after firing systick_handeler callback will jump to garbage location
// so itis recomendded to make call_back function before initialization in main()

void MSTK_SetCallBack(void(*ptr)(void))  //take pointer to function
{
	
	MSTK_CallBack=ptr;   
}
/*
 * take care we make in the CTRL register = 3 in this case the frequency = 8mhz/8
 * so the new one that will operate the systick = 1mhz
 * */

void MSTK_Intialization(void)
{
	MSTK -> CTRL = 3; 
	MSTK -> VAL =100;     //any value put in this register reset the timer
	MSTK -> LOAD=1000000;   //because systick work with 1mhz so this value will loaded as 1s
	
	
}

