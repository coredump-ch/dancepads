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
#include <stdio.h>
#include <plib.h>
#include <usart.h>
#include <spi.h>
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"
#include "piezo.h"
#include "hsi_rgb.h"
#include "spimaster.h"
#include <xc.h>

void main(void) {
    unsigned int touch = 0;
    int* color = 0;
    
    //Initialize Dancepad
    init_oscillator();
    init_lifeled();
//    init_rgbled();
//    init_piezo();
    init_spimaster();
    init_spislave();
    
    //Infinite loop of the programm
    while(1)
    {
//        blink_lifeled();
        blink_spiled();
//        touch = read_piezo();

        
//        color = hsi_rgb(touch);
//        set_rgbled(color[0], color[1], color[2]);

//        printf("end of loop");
    }
 }
