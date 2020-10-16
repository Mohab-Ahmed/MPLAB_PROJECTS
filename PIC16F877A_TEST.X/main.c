/*
 * File:   main.c
 * Author: mohab
 *
 * Created on October 14, 2020, 9:55 PM
 */


#include <xc.h>
#include"config.h"
#define _XTAL_FREQ 4000000      //set the crystal frequency

/*
void main(void) {
    TRISBbits.TRISB0=1;         //Port B0 input
    TRISBbits.TRISB1=0;         //Port B1 output
    PORTBbits.RB1=0;            //output low LED off

    while(1)
    {
        if(PORTBbits.RB0)       
        {
            PORTBbits.RB1=1;
            __delay_ms(250);
            PORTBbits.RB1=0;
            __delay_ms(250);
        }
        else
            PORTBbits.RB1=0;
 
    }
    return;
}
*/
//Another way to do the bitfield masking when writing to registers
void main(void) {
    TRISB0=1;         //Port B0 input
    TRISB1=0;         //Port B1 output
    RB1=0;            //output low LED off

    while(1)
    {
        if(RB0)       
        {
            RB1=1;
            __delay_ms(250);
            RB1=0;
            __delay_ms(250);
        }
        else
            RB1=0;
 
    }
    return;
}
