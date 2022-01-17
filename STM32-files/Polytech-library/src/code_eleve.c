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
/* timer par d�cr�ment d'une variable ou par utilisation du timer 1*/
static void Timer_t1ms(unsigned int period)
{
    unsigned int i;

    for(i = 0; i < period; i++)
    {
        StartTimer_1();						//d�marre le timer

        while(GetUpdateEvent() == 0){;}		//contr�le si overflow du compteur (CNT == ARR)

        ResetUpdateEvent();					//reset du flag

        StopTimer_1();						//arr�t du compteur
    }
}




//---------------------------------------------------------------------------------------
static void Drive_CS_pin(char value)
{
    // A compl�ter ...
}

//----------------------------------------------------------------------------------------
void WriteToDAC(unsigned int value)
{
    chipSelect(LOW);
    SPI1->DR = (1 << 12) | value; // Bit 12 to enable Vout
    while( !(SPI1->SR & SPI_SR_TXE) );
    while(SPI1->SR & SPI_SR_BSY);
    chipSelect(HIGH);
}


//------------------------------------------------------------------------------------------
void SignalTriangle(void)
{
    // A compl�ter ...
}


//------------------------------------------------------------------------------------------
void RestitutionAnalogue(void)
{
    // A compl�ter ...
}


void chipSelect(int status)
{
    if(status == LOW)
    {
        GPIOB->ODR &= ~(GPIO_ODR_ODR_6);
    }
    else
    {
        GPIOB->ODR |= GPIO_ODR_ODR_6;
    }
}
