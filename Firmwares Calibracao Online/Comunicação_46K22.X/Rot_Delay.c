//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <xc.h>
#include "Rot_Delay.h"


//------------------------------------------------------------------------------
// IMPLEMENTA��O DE FUN��ES P�BLICAS
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Fun��o para delay em milisegundos.
//------------------------------------------------------------------------------
void delayMs(unsigned long int milli)
{
    unsigned long int counter;
    for(counter = 0; counter < milli; ++counter) {
        __delay_ms(1);
    }
}


//------------------------------------------------------------------------------
// Fun��o para delay em microsegundos
//------------------------------------------------------------------------------
void delayUs(unsigned long int micro)
{
    unsigned long int counter;
    for(counter = 0; counter < micro; ++counter) {
        __delay_us(1);
    }
}


//------------------------------------------------------------------------------
// Fun��o para delay em segundos
//------------------------------------------------------------------------------
void delaySc(unsigned long int sec)
{
    unsigned long int counter;
    unsigned long int currentSec;
    for(currentSec = 0; currentSec < sec; ++currentSec) {
        for(counter = 0; counter < 100; ++counter) {
            __delay_ms(10);
        }    
    }
}