/********************************** HEADERS ****************************************************************/
#include "stm32f4xx.h"

#include "Uart.h"
#include "Clocks.h"

/********************************** VARIABLES ***************************************************************/


/********************************** SOURCE CODE ************************************************************/
void InitUart1(void)
{
	USART1->CR1 = 0x0000002C;	/*TX & RX enable + RX interrupt enable*/
	USART1->CR2 = 0x00000000;
	USART1->CR3 = 0x00000000;
	USART1->BRR = 0x00000362;	/*baud rate divider - 115200 bauds*/
	USART1->GTPR = 0x00000000;

	USART1->CR1 |= 0x00002000;		/*enable USART 1*/
}

void setup_USART2_RSD(uint32_t baudrate)
{
    RCC->APB1ENR |= (1 << 17);

    USART2->CR1 |= (1 << 13);                // UE
    USART2->CR1 &= ~(1 << 12);               // 8-bit
    USART2->CR2 &= ~(3 << 12);               // 1 stop bit
    USART2->BRR = get_APB1CLK()/baudrate;    // baud rate
    USART2->CR1 |= (1 << 3);                 // TE

    // Activate interrupts
    NVIC->ISER[1] |= (1 << 6);
    NVIC->IP[6] = 0x00;

    USART2->CR1 |= (1 << 2);                 // RE
    USART2->CR1 |= (1 << 5);                 // Interrupt on receive
}

//---------------------------------------------------------------------------------------------------------
void InitUart2(void)
{
	USART2->CR1 = 0x00000008;	/*TX enable*/
	USART2->CR2 = 0x00000000;
	USART2->CR3 = 0x00000000;
	USART2->BRR = 0x000000D9;	/*baud rate divider - 115200 bauds*/
	USART2->GTPR = 0x00000000;

	USART2->CR1 |= 0x00002000;		/*enable USART 2*/
}

//------------------------------------------------------------------------------
void SendByte_Uart1(uint8_t data)
{
	while(!(USART1->SR & 0x00000080));		/*check for TX buffer empty*/

	USART1->DR = data;

	while(!(USART1->SR & 0x00000040));		/*check for transmission complete*/
}

//-------------------------------------------------------------------------------
uint8_t GetByteUart1(void)
{
	return USART1->DR;
}


//-------------------------------------------------------------------------------
uint8_t CheckUart1RxFlag(void)
{
	uint8_t ret;

	if(USART1->SR & 0x00000020)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}

	return ret;
}


//------------------------------------------------------------------------------
void SendByte_Uart2(uint8_t data)
{
	while(!(USART2->SR & 0x00000080));		/*check for TX buffer empty*/

	USART2->DR = data;

	while(!(USART2->SR & 0x00000040));		/*check for transmission complete*/
}
