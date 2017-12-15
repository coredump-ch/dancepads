/* 
 * File:   main.c
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#define _XTAL_FREQ  64000000
#include <P18F23K22.h>
#include <xc.h>
#include "init.h"
#include "lifeled.h"
#include "rgbled.h"

void main(void) {

    init_oscillator();
    init_lifeled();
    init_rgbled();
    
    while(1)
    {
       blink_lifeled();
       blink_rgbled();
    }
 }
