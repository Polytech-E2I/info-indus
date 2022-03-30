#pragma once

#include <stdint.h>

#define TAPS 81
int NEXT_INDEX(int index);
int PREVIOUS_INDEX(int index);
void SHIFT_BUFFER(void);


volatile uint16_t TAMPON[TAPS];
volatile int16_t COEFFS [] =
{
    -8,-8,-8,-9,-9,-9,-9,-10,-10,-10,-10,-11,-11,-11,-11,-12,-12,-12,-12,-13,
    -13,-13,-13,-13,-13,-14,-14,-14,-14,-14,-14,-14,-14,-14,-15,-15,-15,-15,-15,
    -15,985,-15,-15,-15,-15,-15,-15,-14,-14,-14,-14,-14,-14,-14,-14,-14,-13,-13,
    -13,-13,-13,-13,-12,-12,-12,-12,-11,-11,-11,-11,-10,-10,-10,-10,-9,-9,-9,-9,
    -8,-8,-8
};
volatile int INDEX = 0;