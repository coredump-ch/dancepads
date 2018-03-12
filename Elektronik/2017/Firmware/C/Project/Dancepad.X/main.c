/* 
 * File:   main.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

//Includes
#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include <plib.h>
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"
#include "piezo.h"
#include "hsi_rgb.h"
#include <xc.h>

void main(void) {
    unsigned int touch = 0;
    int* color = 0;
    
    //Initialize Dancepad
    init_oscillator();
    init_lifeled();
    init_rgbled();
    init_piezo();
    
    //Infinite loop of the programm
    while(1)
    {
        blink_lifeled();
        touch = read_piezo();
/*       __delay_ms(1);
        touch ++;
        if (touch == 1536)
        {
            touch = 0;
        }*/
        color = hsi_rgb(touch);
        set_rgbled(color[0], color[1], color[2]);

    }
 }
