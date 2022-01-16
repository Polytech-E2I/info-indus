// DESCRIPTION ***************************************************************//

/*This file contains all the function prototypes for the setting of the timer */

// PREVENTING RECURSIVE INCLUSION ********************************************//

#ifndef TIMER_H_
#define TIMER_H_

// APB1 CLOCK FREQUENCY *****************************************************//

#define FREQ_APB1	    45000000


// PROTOTYPES ****************************************************************//
//TIMER 1
void InitTimer_1(void);
void StartTimer_1(void);
void StopTimer_1(void);
uint16_t GetTimer1Count(void);
uint16_t GetUpdateEvent(void);
void ResetUpdateEvent(void);


// ***************************************************************************//

#endif




