/*
 * File:   main.c
 * Author: mohab
 *
 * Created on October 16, 2020, 2:02 AM
 */


#include <xc.h>
#include"config.h"
#define _XTAL_FREQ 4000000      //set the crystal frequency

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
