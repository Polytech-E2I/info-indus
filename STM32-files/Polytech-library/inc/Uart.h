/************************************** DEFINE ******************************************************/


/************************************* FUNCTION PROTOTYPES ******************************************/
void InitUart1(void);
void InitUart2(void);
void SendByte_Uart1(uint8_t data);
void SendByte_Uart2(uint8_t data);
uint8_t CheckUart1RxFlag(void);
uint8_t GetByteUart1(void);
