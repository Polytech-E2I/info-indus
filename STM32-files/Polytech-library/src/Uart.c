/********************************** HEADERS ****************************************************************/
#include "stm32f4xx.h"

#include "Uart.h"

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
