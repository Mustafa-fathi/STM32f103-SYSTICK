/*
 * main.c
 *
 *  Created on: Jul 20, 2018
 *      Author: Hampota
 */
#include "LSTD_TYPES.h"
#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MSTK_interface.h"
static volatile u8 flag=0;

void toggle()
{

	if (flag == 0)
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_HIGH);
		flag=1;
	}
	else
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_LOW);
		flag=0;
	}

}

void main(void )
{

	MRCC_Initialize();
	MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
	MDIO_Initialize();

	MSTK_SetCallBack(toggle);
	MSTK_Intialization();

	while(1)
	{

	}



}



