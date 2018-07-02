/* 
 * File:   main.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

//Includes
#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <htc.h>
#include <xc.h>
#include <stdio.h>
#include <plib.h>
#include <usart.h>
#include <spi.h>
#include "dancepad.h"
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"
#include "piezo.h"
#include "hsi_rgb.h"
#include "spi.h"
#include "i2c.h"
#include "delays.h"
#include <xc.h>

void main(void) {
    unsigned int touch = 0, freq = 2000;
    int* color = 0;
    unsigned char dir = 0;
    
    //Initialize Dancepad
    init_oscillator();
    dir = init_direction();
    init_lifeled();
    init_rgbled();
    init_piezo();
    init_spimaster();
    if (dir == dir_master)
    {
//        init_i2cslave();
    }
    else
    {
        init_spislave();
    }
    
    //Infinite loop of the programm
    while(1)
    {
//        blink_lifeled();
//        freq = rec_i2c(0x01);
//        rec_i2c(12);
        
//        blink_spiled(dir, freq);
        PORTAbits.RA4 = (unsigned int) PIR1bits.SSP1IF;
        touch = read_piezo();
        
        color = hsi_rgb(touch);
        set_rgbled(color[0], color[1], color[2]);

//        printf("end of loop");
    }
 }
