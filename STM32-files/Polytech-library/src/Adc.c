/********************************************************************************/
/*					HEADER FILES												*/
/********************************************************************************/
#include "stm32f4xx.h"
#include "Adc.h"

/********************************************************************************/
/*					STATIC FUNCTION PROTOTYPES								    */
/********************************************************************************/
static void Adc_1_Init(void);

/********************************************************************************/
/*					FUNCTION CODE												*/
/********************************************************************************/
/********************************************************************************/
//	Function Name : InitAdc
//	Description   : This function configure ADC1 and ADC2 registers
// Parameters	 : None
// Retval        : None
/********************************************************************************/
void InitAdc(void)
{
	ADC->CCR = 0x00030000;		/*OK: ADCCLK / 8 (prescaler) - ADC1 & 2 are independant*/

	Adc_1_Init();
}

//-------------------------- ADC 1 -----------------------------------------------
/********************************************************************************/
//	Function Name : Adc_1_Init
//	Description   : This function configure the channel 0 of ADC1 to get the pressure
// Parameters	  : None
// Retval         : None
/********************************************************************************/
static void Adc_1_Init(void)
{
	ADC1->SQR3 = 0x00000000;	/* 1 conversion of channel 0*/

	ADC1->SMPR2 = 0x00000003;	/*56 clock cycles sampling of channel 0*/

	ADC1->CR1 = 0x00000000;		/*resolution = 12 bits + pas d'interruptions*/

	ADC1->CR2 = 0x00000001;		/*enable ADC + pas de trigger + single conversion*/
}

/********************************************************************************/
//	Function Name : ADC_1_StartConversion
//	Description   : This function generates a start of conversion in manual mode
// Parameters	  : None
// Retval         : None
/********************************************************************************/
void ADC_1_StartConversion(void)
{
	ADC1->CR2 |= 0x40000000;		/*bit 30: start conversion*/
}


/********************************************************************************/
//	Function Name : ADC_1_CheckEndOfConversion
//	Description   : This function checks if end of conversion flag is ON
// Parameters	  : None
// Retval         : 1 if end of conversion flag is ON, otherwise 0
/********************************************************************************/
uint8_t ADC_1_CheckEndOfConversion(void)
{
	uint8_t ret;

	ret = ADC1->SR & ADC_EOC;

	return ret;
}

/********************************************************************************/
//	Function Name : ADC_1_ClearEndOfConversion
//	Description   : This function checks if end of conversion flag is ON
// Parameters	  : None
// Retval         : 1 if end of conversion flag is ON, otherwise 0
/********************************************************************************/
void ADC_1_ClearEndOfConversion(void)
{
	ADC1->SR &= ~ADC_EOC;
}


/********************************************************************************/
//	Function Name : ADC_1_GetResult
//	Description   : This function checks if end of conversion flag is ON
// Parameters	  : None
// Retval         : 1 if end of conversion flag is ON, otherwise 0
/********************************************************************************/
uint16_t ADC_1_GetResult(void)
{
	uint16_t result;

	result = ADC1->DR;

	return result;
}

