/* 
 * File:   main.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include <plib.h>
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"
#include "piezo.h"
#include "hsi_rgb.h"

void main(void) {
//    int red = 500;
//    int green = 0;
//    int blue = 0;
    unsigned int touch = 0;
//   unsigned int touch_old = 0;
//    int a = 0;
    int* color = 0;
    
    init_oscillator();
    init_lifeled();
    init_rgbled();
    init_piezo();
    
    while(1)
    {
        blink_lifeled();
        touch = read_piezo();
/*       __delay_ms(1);
        touch ++;
        if (touch == 1536)
        {
            touch = 0;
        }
        /*       if (touch != touch_old)
        {
            a = red;
            red = green;
            green = a;
        }
        blue = touch;*/
        color = hsi_rgb(touch);
        set_rgbled(color[0], color[1], color[2]);
 //       set_rgbled(10*touch, 100*touch, 50*touch);
/*        __delay_ms(1);
        switch (color){
            case 0:
            {
                red++;
                if (red >= 1000)
                {
                    color = 1;
                }
            }
            break;
            case 1:
            {
                green++;
                if (green >= 1000)
                {
                    color = 2;
                }
            }
            break;
            case 2:
            {
                blue++;
                if (blue >= 1000)
                {
                    color = 3;
                }
            }
            break;
            case 3:
            {
                red--;
                if (red <= 0)
                {
                    color = 4;
                }
            }
            break;
            case 4:
            {
                green--;
                if (green <= 0)
                {
                    color = 5;
                }
            }
            break;
            case 5:
            {
                blue--;
                if (blue <= 0)
                {
                    color = 0;
                }
            }
            break;
            default:
            {
                color = 0;
            }
            break;
        }*/
    }
 }
