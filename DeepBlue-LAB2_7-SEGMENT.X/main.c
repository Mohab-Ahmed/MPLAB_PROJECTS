/*
 * File:   main.c
 * Author: mohab
 *
 * Created on October 16, 2020, 3:26 AM
 */

/*7-segments to binary (common anode)
 * 0 = ABCDEF10 = 0x2
 * 1 = 1BC11110 = 0x9E
 * 2 = AB1DE1G0 = 0x24
 * 3 = ABCD11G0 = 0xC
 * 4 = 1BC11FG0 = 0x98
 * 5 = A1CD1FG0 = 0x48
 * 6 = A1CDEFG0 = 0x40
 * 7 = ABC11110 = 0x1E
 * 8 = ABCDEFG0 = 0x0
 * 9 = ABCD1FG0 = 0x8
*/

/*7-segments to binary (common kathode)
 * 0 = ABCDEF00 = 0xFC
 * 1 = 0BC00000 = 0x60
 * 2 = AB0DE0G0 = 0xDA
 * 3 = ABCD0000 = 0xF2
 * 4 = 0BC00FG0 = 0x66
 * 5 = A0CD0FG0 = 0xB6
 * 6 = A0CDEFG0 = 0xBE
 * 7 = ABC00000 = 0xE0
 * 8 = ABCDEFG0 = 0xFE
 * 9 = ABCD0FG0 = 0xF6
*/

#include <xc.h>
#include"config.h"
#include<stdint.h>
#define _XTAL_FREQ 4000000      //set the crystal frequency

void main(void) {
    //uint8_t segment[10]={0x2,0x9E,0x24,0xC,0x98,0x48,0x40,0x1E,0x0,0x8};        //common anode    
    uint8_t segment[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};  //common kathode
    
    TRISB=0;                    //PORT B as output  
    
    //PORTD=1;                    //output HIGH means 7-segment OFF by default        //anode 
    PORTB=0;                    //output HIGH means 7-segment OFF by default        //cathode
    while(1)
    {
        for(uint8_t i=0;i<10;i++)
        {
            PORTB=segment[i];
            __delay_ms(600);
        }
    }
    return;
}
