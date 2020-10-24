/*
 * File:   main.c
 * Author: mohab
 *
 * Created on October 24, 2020, 3:09 AM
 */


#include <xc.h>
#include<stdint.h>
#include"config.h"
#define _XTAL_FREQ 4000000      //set the crystal frequency

#define NUM_OVERFLOW 20
#define PRELOAD 15536           //the value to load in TMR1 bit to start counting from

/* if we have 16 as NUM_OVERFLOW so we PRELOAD 3036
 * if we have 20 as NUM_OVERFLOW so we PRELOAD 15536
 */

uint8_t count=0;                //count for ticks

/*
void initialize_timer()
{
    TMR1=0;                     //clear the timer 1 bit to start counting from 0
    T1CKPS1=0;                  //prescaler to 0
    T1CKPS0=0;                  // // // // // //
    TMR1CS=0;                   //use internal clock Fosc/4
    TMR1ON=1;                   //Enable timer bit
}
void main(void) {
    TRISB=0;                    //port B as output
    RB0=0;                      //output low
    initialize_timer();         //call the function to set our timer
    GIE=1;                      //general interrupt enable bit
    PEIE=1;                     //Peripheral Interrupt Enable bit
    TMR1IF=0;                   //making sure the timer flag is cleared
    TMR1IE=1;                   //timer 1 enable bit
    
    while(1)
    {
        
    }
    return;
}

void __interrupt() ISR()
{
    if(TMR1IF)
    {
        count++;
        if(count==NUM_OVERFLOW)
        {
           RB0=~RB0;              //toggle the led every 1 sec 
           count=0;             //clear the counter for ticks
        }
        TMR1IF=0;               //clear timer 1 flag after we finish
    }
}
*/

//another variant of the same program but with using timer pre-load to have a 100% accurate timer


void initialize_timer()
{
    TMR1=PRELOAD;               //Preload the timer register              
    T1CKPS1=0;                  //prescaler to 0
    T1CKPS0=0;                  // // // // // //
    TMR1CS=0;                   //use internal clock Fosc/4
    TMR1ON=1;                   //Enable timer bit
}
void main(void) {
    TRISB=0;                    //port B as output
    RB0=0;                      //output low
    initialize_timer();         //call the function to set our timer
    GIE=1;                      //general interrupt enable bit
    PEIE=1;                     //Peripheral Interrupt Enable bit
    TMR1IF=0;                   //making sure the timer flag is cleared
    TMR1IE=1;                   //timer 1 enable bit
    
    while(1)
    {
        
    }
    return;
}

void __interrupt() ISR()
{
    if(TMR1IF)
    {
        TMR1=PRELOAD;           //always apply it here too cuz when overflow occurs it start counting from 0 again         
        count++;
        if(count==NUM_OVERFLOW)
        {
           RB0=~RB0;            //toggle the led every 1 sec 
           count=0;             //clear the counter for ticks
        }
        TMR1IF=0;               //clear timer 1 flag after we finish
    }
}
