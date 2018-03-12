/* 
 * File:   hsirgb.c
 * Author: astoc
 *
 * Created on 30. Januar 2018, 20:58
 */

#include <xc.h>

int * hsi_rgb(int h)
{
    int r, g, b = 0;
    static int rgb[3];
    
    //Calculate RGB hexagon
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
    
    //Return colors
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    
    return rgb;
}
