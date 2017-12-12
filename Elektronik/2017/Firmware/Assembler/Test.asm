; TODO INSERT CONFIG CODE HERE USING CONFIG BITS GENERATOR

;LIST    P=PIC18F23K22
#include <p18f23k22.inc>
 
;CONFIG FOSC=LP, IESO=ON, PRICLKEN=ON, PLLCFG=ON
;CONFIG FOSC=INTIO67, IESO=OFF, PRICLKEN=ON, PLLCFG=OFF
CONFIG FOSC=INTIO67, PLLCFG=OFF, PRICLKEN=ON, FCMEN = OFF, IESO = OFF
CONFIG DEBUG=OFF
    

 
RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program

; TODO ADD INTERRUPTS HERE IF USED

MAIN_PROG CODE                      ; let linker place main program

Delay1 res 1
Delay2 res 1
Delay3 res 1
 
 
START
; CONFIGURE OSCILLATOR

MOVLW 70h
MOVWF OSCCON

MOVLW 04h
MOVWF OSCCON2

MOVLW 40h
MOVWF OSCTUNE

CLRF PORTA
CLRF LATA
CLRF TRISA
 
CLRF Delay1
CLRF Delay2

MainLoop:

BTG PORTA, RA4

;MOVLW 0F0h
SETF Delay1
    
;MOVLW 01h
;SETF Delay2

MOVLW 007h
MOVWF Delay2
    
Bla:
Delay:
    DECFSZ Delay1,1
    GOTO Delay
    DECFSZ Delay2,1
    ;GOTO Bla
    ;DECFSZ Delay3,1
    
GOTO MainLoop                         ; loop forever

END