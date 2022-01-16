// DESCRIPTION ***************************************************************//
/* Functions in this file are used to:
 * - configure main clock (HCLK) and peripheral clocks (APB1, APB2...) of the system
 * - enable clock of specific peripherals
 */

// HEADER FILES **************************************************************//
#include "stm32f4xx.h"
#include "Clocks.h"

// FUNCTIONS *****************************************************************//
static void EnablePeripheralClocks(void);

// ***********************************************************************************************************************//
// Function name   : ClockConfiguration
// Description     : Define the value of each clock of the device :
//					 SYSCLK : Define by a PLL
//
//	  					   PLL_CLK		N       	16MHz    100
//	  			SYSCLK =   ---  	* -----   =   	---- * -----   =   100 MHz
//	  					  	M   		P         	  8       2
//
//					 HCLK : Set at its maximum value : 100MHz (= SYSCLK / PRESCALER)
//					 PCLK1: Set at its maximum value : 25MHz (= SYSCLK / PRESCALER)
//					 PCLK2: Set at its maximum value : 50MHz (= SYSCLK / PRESCALER)
// Parameters      : None
// Retval          : None
// ***********************************************************************************************************************//
void ClockConfiguration(void)
{
	uint32_t temp;

	//Set Flash latency (wait states) according to CPU frequency HCLK
	FLASH->ACR |= 0x00000003;		//set to 3 wait states 90MHz < HCLK < 120MHz

	temp = (FLASH->ACR & 0x0000000F);	//check latency

	if(temp != 3)
	{
		//issue @@@@
	}
	else
	{
		//OK
	}

	//set PLL configuration
	RCC->PLLCFGR = 0x22001908;

	//set peripheral clocks prescaler
	RCC->CFGR = (RCC_CFGR_SWS_PLL | RCC_CFGR_SW_PLL); 	//0x0000000A;

	//enable PLL clock and HSI
	RCC->CR |= (RCC_CR_PLLON | RCC_CR_HSION);			//0x01000001;

	//wait for PLL clock ready
	while(!(RCC->CR & RCC_CR_PLLRDY)){;}
}

// ***********************************************************************************************************************//
// Function name : Enabling_Clocks
// Description     : Activation of each peripheral's clock used
// Parameters      : None
// Retval          : None
// ***********************************************************************************************************************//
void SetClocks(void)
{
	EnablePeripheralClocks();
}

// ***********************************************************************************************************************//
// Function name : EnablePeripheralClocks
// Description     : enable peripheral clocks used within application
// Parameters      : None
// Retval          : None
// ***********************************************************************************************************************//
static void EnablePeripheralClocks(void)
{
	//AHB1 clock
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN
					| RCC_AHB1ENR_GPIOBEN);		//enable GPIOA, B

	//APB2 clock
	RCC->APB2ENR |= (RCC_APB2ENR_ADC1EN
					| RCC_APB2ENR_SPI1EN
					| RCC_APB2ENR_TIM1EN
					| RCC_APB2ENR_SYSCFGEN);	//enable ADC1, TIM1, SYSCFG
}
