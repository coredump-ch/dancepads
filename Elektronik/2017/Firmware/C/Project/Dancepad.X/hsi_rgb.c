#define _XTAL_FREQ  64000000
#include <p18f23k22.h>
#include <xc.h>
#include <math.h>
#include "init.h"
#include "hsi_rgb.h"

int * hsi_rgb(int h)
{
    int temp = 0;
    int r, g, b = 0;
    int rgb[3];
    
   // h = h * 3 / 2;
    
    if(h < 255)
    {
        r = 255;
        g = 0;
        b = h;
    }
    else
    {
        if(h < 511)
        {
            r = 511 - h;
            g = 0;
            b = 255;
        }
        else
        {
            if(h < 767)
            {
                r = 0;
                g = h - 512;
                b = 255;
            }
            else
            {
                if(h < 1023)
                {
                    r = 0;
                    g = 255;
                    b = 1023 - h;
                }
                else
                {
                    if(h < 1279)
                    {
                        r = h - 1024;
                        g = 255;
                        b = 0;
                    }
                    else
                    {
                        if(h < 1535)
                        {
                            r = 255;
                            g = 1535 - h;
                            b = 0;
                        }
                        else
                        {
                            r = 0;
                            g = 0;
                            b = 0;
                        }
                    }
                }
            }
        }
    }
        
/*    if (h%512 <= 170)
    {
        r = 255;
        g = 0;
        b = h%512*3/2;
    }
    else if (h%512 <= 341)      
    {
        r = 255-h%512*3/2;
        g = 0;
        b = 255;
    }
    else   
    {
        r = 0;
        g = h%512*3/2;
        b = 255;
    }    
    
    if (h > 512)
    {
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
    }
    
    r = 4*r;
    g = 4*g;
    b = 4*b;*/
    
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    
    return &rgb;
}
