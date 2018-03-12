/* 
 * File:   init.h
 * Author: astoc
 *
 * Created on 12. Dezember 2017, 15:26
 */

#ifndef INIT_H
#define	INIT_H

//Configure processor


//CONFIG1H
//--------
//Oscillator Selection bits->Internal oscillator block
#pragma config FOSC = INTIO67

//4X PLL Enable->Oscillator used directly
#pragma config PLLCFG = OFF

//Primary clock enable bit->Primary clock enabled
#pragma config PRICLKEN = ON

//Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor disabled
#pragma config FCMEN = OFF

//Internal/External Osc. Switchover bit->Oscillator Switchover mode disabled
#pragma config IESO = OFF       


//CONFIG2L
//--------
//Power-up Timer Enable bit->Power up timer disabled
#pragma config PWRTEN = OFF

//Brown-out Rst Ena. bits->Brown-out Rst ena. in hw only (SBOREN is disabled)
#pragma config BOREN = SBORDIS

//Brown Out Reset Voltage bits->VBOR set to 1.90 V nominal
#pragma config BORV = 190


//CONFIG2H
//--------
//Watchdog Timer Enable bits->Watchdog timer is disabled. SWDTEN has no effect.
#pragma config WDTEN = OFF

//Watchdog Timer Postscale Select bits->1:32768
#pragma config WDTPS = 32768


//CONFIG3H
//--------
//CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config CCP2MX = PORTC1  
#pragma config PBADEN = ON      // PORTB A/D Enable bit->PORTB<5:0> pins are configured as analog input channels on Reset
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit->P3A/CCP3 input/output is multiplexed with RB5
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up->HFINTOSC output and ready status are not delayed by the oscillator stable status
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit->T3CKI is on RC0
#pragma config P2BMX = PORTB5   // ECCP2 B output mux bit->P2B is on RB5
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit->MCLR pin enabled, RE3 input pin disabled


//CONFIG4L
//--------
//Stack Full/Underflow Reset Enable bit->Stack full/underflow will cause Reset
#pragma config STVREN = ON

//Single-Supply ICSP Enable bit->Single-Supply ICSP enabled if MCLRE is also 1
#pragma config LVP = ON

//Ext. Instr. Ena bit->Instr. set ext. and Indexed Addressing mode disabled 
#pragma config XINST = OFF

//Background Debug->Disabled
#pragma config DEBUG = OFF


//CONFIG5L
//--------
//Code Protection Block 0->Block 0 (000200-000FFFh) not code-protected
#pragma config CP0 = OFF

//Code Protection Block 1->Block 1 (001000-001FFFh) not code-protected
#pragma config CP1 = OFF


//CONFIG5H
//--------
//Boot Block Code Protection bit->Boot block (000000-0001FFh) not code-protected
#pragma config CPB = OFF

//Data EEPROM Code Protection bit->Data EEPROM not code-protected
#pragma config CPD = OFF


//CONFIG6L
//--------
//Write Protection Block 0->Block 0 (000200-000FFFh) not write-protected
#pragma config WRT0 = OFF

//Write Protection Block 1->Block 1 (001000-001FFFh) not write-protected
#pragma config WRT1 = OFF


//CONFIG6H
//--------
//Config Reg. Write Prot. bit->Config reg. (300000-3000FFh) not write-protected
#pragma config WRTC = OFF

//Boot Block Write Prot. bit->Boot Block (000000-0001FFh) not write-protected
#pragma config WRTB = OFF

//Data EEPROM Write Protection bit->Data EEPROM not write-protected
#pragma config WRTD = OFF


//CONFIG7L
//--------
//Block 0 (000200-000FFFh) not prot. from table reads executed in other blocks
#pragma config EBTR0 = OFF

//Block 1 (001000-001FFFh) not prot. from table reads executed in other blocks
#pragma config EBTR1 = OFF


//CONFIG7H
//--------
//Boot Block (000000-0001FFh) not prot. from reads executed in other blocks
#pragma config EBTRB = OFF


//Define subroutines

//Init oscillator subrutine
void init_oscillator();


#endif