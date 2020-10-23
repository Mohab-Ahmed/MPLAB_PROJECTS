/*
 * File:   main.c
 * Author: mohab
 *
 * Created on October 21, 2020, 1:44 AM
 */


#include <xc.h>
#include<stdint.h>
#include"config.h"
#define _XTAL_FREQ 4000000      //set the crystal frequency

#define NUM_OF_STEPS 48         //Angle per step is 7.5 so to do 360 angle u need 360/7.5=48 steps

//First program to just turn it one side then delay then other side

void main(void) {
    TRISA=1;                    //PORT A as input
    TRISB=0;                    //PORT B as output
    PORTB=0;                    //output low
    
    uint8_t t=0;                //variable to track the position of the coil to turn on
    while(1)
    {
            for(int i=0;i<NUM_OF_STEPS;i++)     //turn CW
            {
                PORTB=(1<<t);
                __delay_ms(70);
                t++;
                if(t==4)
                    t=0;
            }
            __delay_ms(1000);                   //delay 1 sec between turns
            t=0;
            for(int i=0;i<NUM_OF_STEPS;i++)     //turn CCW
            {
                PORTB = (8>>t); 
                t++;
                __delay_ms(70);
                if(t==4)
                    t=0;
            }
    }
    return;
}


//Still work in progress

/*
//Second program where we use a push button to control which direction to turn
void main(void) {
    TRISA=1;                    //PORT A as input
    TRISB=0;                    //PORT B as output
    PORTB=0;                    //output low
    
    uint8_t t=0;                //variable to track the position of the coil to turn on
    while(1)
    {
        if(RA0)
        {
            for(int i=0,t=0;i<NUM_OF_STEPS;i++)     //turn CW
            {
                PORTB=(1<<t);
                __delay_ms(70);
                t++;
                if(t==4)
                    t=0;
            }
        }
           
        if(RA1)
        {
             for(int i=0,t=0;i<NUM_OF_STEPS;i++)     //turn CCW
            {
                PORTB = (8>>t); 
                t++;
                __delay_ms(70);
                if(t==4)
                    t=0;
            }
        }
    }
    return;
}
*/