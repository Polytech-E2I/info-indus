/* Polytech Grenoble */
/* IESE/E2i */
/* TP SPI */


/********************************************************************************/
/*					HEADER FILES												*/
/********************************************************************************/
#include "stm32f4xx.h"
#include "Adc.h"
#include "Spi.h"
#include "Timer.h"

#include "code_eleve.h"

/********************************************************************************/
/*					STATIC														*/
/********************************************************************************/
static void Timer_t1ms(unsigned int period);
static void Drive_CS_pin(char value);

/********************************************************************************/
/*					DEFINE														*/
/********************************************************************************/


/********************************************************************************/
/*					VARIABLES													*/
/********************************************************************************/
unsigned int count;

/********************************************************************************/
/*					SOURCE CODE													*/
/********************************************************************************/
/* timer par décrément d'une variable ou par utilisation du timer 1*/
static void Timer_t1ms(unsigned int period)
{
	unsigned int i;

	for(i = 0; i < period; i++)
	{
		StartTimer_1();						//démarre le timer

		while(GetUpdateEvent() == 0){;}		//contrôle si overflow du compteur (CNT == ARR)

		ResetUpdateEvent();					//reset du flag

		StopTimer_1();						//arrêt du compteur
	}
}




//---------------------------------------------------------------------------------------
static void Drive_CS_pin(char value)
{
	// A compléter ...
}

//----------------------------------------------------------------------------------------
void WriteToDAC(unsigned int value)
{
	// A compléter ...
}


//------------------------------------------------------------------------------------------
void SignalTriangle(void)
{
	// A compléter ...
}


//------------------------------------------------------------------------------------------
void RestitutionAnalogue(void)
{
	// A compléter ...
}


