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
        init_i2cslave();
        master_dancepad(dir);
    }
    else
    {
        init_spislave();
        slave_dancepad(dir);
    }
 }

//******************************************************************************
// Master
//******************************************************************************
void master_dancepad(unsigned char direction)
{
    int i2cTxBufEmpty = TRANSMITTED;
    int i2cRxBufEmpty = NOTRECEIVED;
    unsigned char UsbRec[I2CDATASIZE] = {0};
    unsigned char UsbTra[I2CDATASIZE] = {0};
    unsigned char val[I2CDATASIZE] = {0};
    unsigned int piezoValues[5] = {0};
    int lifeLedSyncActive = 0;
    
    //Infinite loop of the programm
    while(1)
    {
        i2cRxBufEmpty = get_i2c_data(val);
        
        if (i2cRxBufEmpty == RECEIVED)
        {
            for (int i = 0; i < I2CDATASIZE; i++)
            {
                UsbRec[i] = val[i];
                send_spimaster(val[i]);
            }
        }
        else
        {
            for (int i = 0; i < I2CDATASIZE; i++)
            {
                UsbRec[i] = 0;
            }
        }
        
        switch (UsbRec[0])
        {
            case BEYOURSELF:
            {
                blink_lifeled(direction);
            }
            break;
            
            case LIFELEDSYNCH:
            {
                set_lifeLed(UsbRec[1]);
                lifeLedSyncActive = 1;
            }
            break;
            
            case LIFELEDBLINK:
            {
                lifeLedSyncActive = 0;
            }
            break;
            
            case SETRGBCOLOR:
            {
                set_rgbled(UsbRec[1], UsbRec[2], UsbRec[3]);
            }
            break;
            
            case READPIEZO:
            {
                UsbTra[6] = read_piezo(piezoValues);
                
                for (int j = 0; j < 5; j++)
                {
                    UsbTra[j] = piezoValues[j];
                }
                
                i2cTxBufEmpty = send_i2c_data(UsbTra);
            }
            break;
            
            default: 
            {
                if (lifeLedSyncActive == 0)
                {
                    blink_lifeled(direction);
                }
//                color = hsi_rgb(touch);
//                set_rgbled(color[0], color[1], color[2]);
            }
            break;
        }  
    }
}


//******************************************************************************
// Slave
//******************************************************************************
void slave_dancepad(unsigned char direction)
{
    int spiRxBufEmpty = NOTRECEIVED;
    unsigned char spiData[SPIDATASIZE] = {0};
    unsigned char val[SPIDATASIZE] = {0};
    unsigned char spiRec[SPIDATASIZE] = {0};
    int lifeLedSyncActive = 0;
    
    //Infinite loop of the programm
    while(1)
    {
        spiRxBufEmpty = get_spi_data(val);
        
        if (spiRxBufEmpty == RECEIVED)
        {
            for (int i = 0; i < SPIDATASIZE; i++)
            {
                spiRec[i] = val[i];
                send_spimaster(val[i]);
            }
        }
        else
        {
            for (int i = 0; i < SPIDATASIZE; i++)
            {
                spiRec[i] = 0;
            }
        }
        
        switch (spiRec[0])
        {
            case BEYOURSELF:
            {
                blink_lifeled(direction);
            }
            break;
            
            case LIFELEDSYNCH:
            {
                set_lifeLed(spiRec[1]);
                lifeLedSyncActive = 1;
            }
            break;
            
            case LIFELEDBLINK:
            {
                lifeLedSyncActive = 0;
            }
            break;
            
            case SETRGBCOLOR:
            {
                set_rgbled(spiRec[1], spiRec[2], spiRec[3]);
            }
            break;
            
            case READPIEZO:
            {
//                UsbTra[6] = read_piezo(piezoValues);
                
                for (int j = 0; j < 5; j++)
                {
//                    UsbTra[j] = piezoValues[j];
                }
                
//                i2cTxBufEmpty = send_i2c_data(UsbTra);
            }
            break;
            
            default: 
            {
                if (lifeLedSyncActive == 0)
                {
                    blink_lifeled(direction);
                }
//                color = hsi_rgb(touch);
//                set_rgbled(color[0], color[1], color[2]);
            }
            break;
        }  
    }
}