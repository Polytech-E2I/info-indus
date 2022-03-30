#include "filtre.h"
#include "code_eleve.h"
#include "Adc.h"

int NEXT_INDEX(int index)
{
    if(index >= (TAPS-1))
    {
        return 0;
    }
    else
    {
        return index+1;
    }
}
int PREVIOUS_INDEX(int index)
{
    if(index <= 0)
    {
        return TAPS-1;
    }
    else
    {
        return index-1;
    }
}

void SHIFT_BUFFER(void)
{
    for(int i = TAPS-1 ; i >= 0 ; --i)
    {
        TAMPON[PREVIOUS_INDEX(i)] = TAMPON[i];
    }
}

void RemplissageBuffer(void)
{
    Timer_t1ms(8);
    #if 0

    WriteToDAC(ADC_1_GetResult());

    #else
        SHIFT_BUFFER();

        ADC_1_StartConversion();
        while(!ADC_1_CheckEndOfConversion());

        TAMPON[0] = ADC_1_GetResult();

        ADC_1_ClearEndOfConversion();
    #endif
}