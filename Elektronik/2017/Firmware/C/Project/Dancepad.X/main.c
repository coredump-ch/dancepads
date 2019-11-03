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
    unsigned char dir = 0;
    int i2cTxBufEmpty = TRANSMITTED;
    int i2cRxBufEmpty = NOTRECEIVED;
    unsigned char arr[I2CDATASIZE] = {0};
    unsigned char val[I2CDATASIZE] = {0};
    unsigned char mul = 2;
    
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
        i2cRxBufEmpty = get_i2c_data(val);
        mul = val[0];
        
        for (int i = 0; i < I2CDATASIZE; i++)
        {
            arr[i] = val[i];
        }
        
        if (arr[0] == 1)
        {
          set_rgbled(arr[1], arr[2], arr[3]);  
        }
        else
        {
            blink_spiled(dir, freq*mul);
            touch = read_piezo();

            color = hsi_rgb(touch);
            set_rgbled(color[0], color[1], color[2]);
        }
        
        i2cTxBufEmpty = send_i2c_data(arr);
    }
 }
