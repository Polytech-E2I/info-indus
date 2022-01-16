/*
 * code-eleve.h
 *
 *  Created on: 1 oct. 2017
 *      Author: admin
 */

#ifndef INC_CODE_ELEVE_H_
#define INC_CODE_ELEVE_H_

#define CONFIG_BITS_PORTA	0x00003000
#define CONFIG_BITS_PORTB	0x0000B000

#define LOW					0
#define HIGH				1

#define BIT6_MASK			0x00000040

void WriteToDAC(unsigned int value);
void SignalTriangle(void);
void RestitutionAnalogue(void);

#endif /* INC_CODE_ELEVE_H_ */
