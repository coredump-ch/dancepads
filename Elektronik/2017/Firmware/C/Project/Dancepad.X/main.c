/* 
 * File:   main.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

//Includes
#define _XTAL_FREQ  64000000
#include <xc.h>
#include <htc.h>
#include <stdio.h>
#include "spi.h"
#include "dancepad.h"
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"
#include "piezo.h"
#include "hsi_rgb.h"
#include "spi.h"
#include "i2c.h"
#include <xc.h>

void main(void) {
    unsigned int touch = 0, freq = 1000;
    int* color = 0;
    int i = 0;
    unsigned char dir = 0;
    unsigned char arr[I2CDATASIZE] = { 1, 2, 3, 4, 5, 6, 7, 8};     // Array just temporarily needed
    int i2cTxBufEmpty = TRANSMITTED;
    
    //Initialize Dancepad
    init_oscillator();
    dir = init_direction();
    init_lifeled();
    init_rgbled();
    init_piezo();
    init_spimaster();
    if (dir == dir_master)
    {
        init_i2cslave();
    }
    else
    {
        init_spislave();
    }
    
    //Infinite loop of the programm
    while(1)
    {   
        blink_spiled(dir, freq);
        touch = read_piezo();
        
        color = hsi_rgb(touch);
        set_rgbled(color[0], color[1], color[2]);
        arr[0] = 1;     // Array allocation just temporarily
        arr[1] = 2;
        arr[2] = 3;
        arr[3] = 4;
        arr[4] = 5;
        arr[5] = 6;
        arr[6] = 7;
        i2cTxBufEmpty = send_i2c_data(arr);
    }
 }
