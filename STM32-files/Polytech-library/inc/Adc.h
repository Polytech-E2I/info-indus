// DESCRIPTION ***************************************************************//

/*  This file contains all the function prototypes for the ADC's settings */

// PREVENTING RECURSIVE INCLUSION ********************************************//

#ifndef ADC_H_
#define ADC_H_


// DEFINE ********************************************************************//
//ADC Status register -- example of what to do --
#define ADC_OVR				0x0020
#define ADC_STRT			0x0010
#define ADC_JSTRT			0x0008
#define ADC_JEOC			0x0004
#define ADC_EOC				0x0002
#define ADC_AWD				0x0001

// PROTOTYPES ****************************************************************//
void InitAdc(void);

//ADC 1
void ADC_1_StartConversion(void);
uint8_t ADC_1_CheckEndOfConversion(void);
void ADC_1_ClearEndOfConversion(void);
uint16_t ADC_1_GetResult(void);

//ADC 2
void ADC_2_StartConversion(void);
uint8_t ADC_2_CheckEndOfConversion(void);
void ADC_2_ClearEndOfConversion(void);
uint16_t ADC_2_GetResult(void);


// ***************************************************************************//

#endif



