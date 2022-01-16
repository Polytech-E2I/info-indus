/* Polytech Grenoble */
/* Technologie de l'information pour la santé*/
/*TP 2*/

/********************************************************************************/
/*					HEADER FILES												*/
/********************************************************************************/
#include "stm32f4xx.h"

#include "Timer.h"

/********************************************************************************/
/*					SOURCE CODE													*/
/********************************************************************************/
//----------------------- TIMER 1 ----------------------------------------------
/********************************************************************************/
//	Function Name : InitTimer_1
//	Description   : This function configures Timer 1 registers
// Parameters	 : None
// Retval        : None
/********************************************************************************/
void InitTimer_1(void)
{
	TIM1->CR1 &= ~0x0001;	/*disable Timer 1*/

	TIM1->PSC = 9999;		/*10 KHz*/
	TIM1->ARR = 10;

	TIM1->CR1 = 0x0000;		/*set CR1*/
	TIM1->CR2 = 0x0000;		/*trigger output*/
}

/********************************************************************************/
//	Function Name : StartTimer_1
//	Description   : This function starts timer 1 in counting mode
// Parameters	 : None
// Retval        : None
/********************************************************************************/
void StartTimer_1(void)
{
	TIM1->CNT = 0x0000;			/*clear timer 1 counter*/
	TIM1->CR1 |= 0x0001;		/*enable timer 1*/
}

/********************************************************************************/
//	Function Name : StopTimer_1
//	Description   : This function stops timer 1 in counting mode
// Parameters	 : None
// Retval        : None
/********************************************************************************/
void StopTimer_1(void)
{
	TIM1->CR1 &= ~0x0001;		/*stop timer 1*/
}


/********************************************************************************/
//	Function Name : GetTimer1Count
//	Description   : This function returns current counter value of timer 1
// Parameters	 : None
// Retval        : current counter value
/********************************************************************************/
uint16_t GetTimer1Count(void)
{
	return (uint16_t) (TIM1->CNT);
}

/********************************************************************************/
//	Function Name : GetUpdateEvent
//	Description   : This function returns 1 if an update event occured (overflow of timer counter)
// Parameters	 : None
// Retval        : update event flag
/********************************************************************************/
uint16_t GetUpdateEvent(void)
{
	return ((uint16_t)(TIM1->SR) & 0x0001);
}

/********************************************************************************/
//	Function Name : ResetUpdateEvent
//	Description   : This function reset update event flag
// Parameters	 : None
// Retval        : None
/********************************************************************************/
void ResetUpdateEvent(void)
{
	TIM1->SR &= ~0x0001;
}
