/**************************** HEADER **************************************************************/
#include "stm32f4xx.h"

#include "Spi.h"
#include "code_eleve.h"


/**************************** CODE *****************************************************************/
// ***********************************************************************************************************************//
// Function  name  : Spi1_Init
// Description     : init spi ports
// Parameters      : N/A
// Return          : N/A
// ***********************************************************************************************************************//
void Spi1_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;

    GPIOA->MODER |= GPIO_MODER_MODER5_1 | GPIO_MODER_MODER7_1; // PA5 and PA7 in Alternate
    GPIOA->AFR[0] |= (0x5 << 20) | (0x5 << 28); // PA5 and PA7 in AF5 mode (SPI1 SCK & MOSI)

    GPIOB->MODER |= GPIO_MODER_MODER6_0; // PB6 in output mode


    SPI1->CR1 |=
          SPI_CR1_MSTR  // Master mode
        | SPI_CR1_BR_0
        | SPI_CR1_BR_1
        | SPI_CR1_BR_2
        | SPI_CR1_CPHA  // CPHA = 1
        | SPI_CR1_CPOL  // CPOL = 1
        | SPI_CR1_DFF   // 16 bit frames
        | SPI_CR1_SSM
        | SPI_CR1_SSI
        | SPI_CR1_SPE;  // SPI enable

    chipSelect(LOW);
}


// ***********************************************************************************************************************//
// Function  name  : Spi1Write
// Description     : Write 1 byte on SPI 1 port
// Parameters      : data to be written
// Return          : N/A
// ***********************************************************************************************************************//
void Spi1Write(unsigned int data)
{
    // A compl�ter ...
}



