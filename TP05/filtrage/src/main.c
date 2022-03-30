/* Polytech Grenoble */
/* IESE/E2i */
/* TP SPI */

/********************* INCLUDES *********************************/
#include "stm32f4xx.h"

#include "Adc.h"
#include "code_eleve.h"
#include "Clocks.h"
#include "Port_conf.h"
#include "Spi.h"
#include "Timer.h"
#include "Uart.h"


/********************** VARIABLES *********************************************************************/
unsigned int adc_value;
unsigned int inter_value;
volatile unsigned int g_value = 0x7FF;


/*************************** CODE **********************************************************************/
int main(void)
{
    //Init clock and flash
    SystemInit();

    // Setting the clock's source and setting the prescaler of HCLK, PCLK1 & PCLK2
    ClockConfiguration();

    SetClocks(); 			// set peripherals clocks

    InitPeripheral();		// Init peripheral I/O's

    InitAdc();				//init ADC configuration
    //Adc_1_Init();

    InitTimer_1();			//init timer 1

//	InitInterrupt();		//init interrupt handlers

    Spi1_Init();			//init SPI mode

    for(;;)
    {
        //WriteToDAC(g_value);

        //SignalTriangle();
    #if 1
        RemplissageBuffer();
    #else
        GPIOB->ODR |= GPIO_ODR_ODR_0;

        RestitutionAnalogue();

        GPIOB->ODR &= ~GPIO_ODR_ODR_0;
    #endif
    }
}
