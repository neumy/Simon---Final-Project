/*
 * File:   neuma346_lab3_CLib_keypad.c
 * Author: Emily & Mckenzie
 *
 * Created on February 21, 2018, 4:29 PM
 */

#include "xc.h"

#include "neuma346_lab3_asmLib_v001.h"

//Initiates pins and pull-up resistors to the desired values. 
void initKeyPad(){
    AD1PCFG = 0x9fff; //Digital values
    
    //Sets TRISA<0:3> pins as outputs
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    
    //Sets corresponding pull-up resistors
    CNPU1bits.CN2PUE = 1;
    CNPU1bits.CN3PUE = 1;
    CNPU2bits.CN30PUE = 1;
    CNPU2bits.CN29PUE = 1;
    
    //Sets TRISB<12:15> pins as inputs
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB15 = 0;
    
}


//Runs through each row of the keypad and determines if any of the buttons are being pressed
//The function does this by setting the desired row to low, and then checking if each column is reading as low
//When a row is read as low, then the corresponding button is being pressed, and the correct key value
//is returned. Code runs significantly faster than human reaction speeds, so the button press will always be read.
char readKeyPadRAW(){
    char myChar = 0; //Sets a default value for the character, in order to determine when no button was pressed

    //Sets row 8 to low
    LATBbits.LATB12 = 0;
    LATBbits.LATB13 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 1;

    //Checks if a button is being pressed
    ejn_wait_1us();
    if(PORTAbits.RA3 == 0){
        myChar = '1';
    }
    if(PORTAbits.RA2 == 0){
        myChar = '2';
    }
    if(PORTAbits.RA1 == 0){
        myChar = '3';
    }
    if(PORTAbits.RA0 == 0){
        myChar = 'A';
    }


    //Sets row 7 to low
    LATBbits.LATB12 = 1;
    LATBbits.LATB13 = 0;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 1;

    //Checks if a button is being pressed
    ejn_wait_1us();
    if(PORTAbits.RA3 == 0){
        myChar = '4';
    }
    if(PORTAbits.RA2 == 0){
        myChar = '5';
    }
    if(PORTAbits.RA1 == 0){
        myChar = '6';
    }
    if(PORTAbits.RA0 == 0){
        myChar = 'b';
    }


    //Sets row 6 to low
    LATBbits.LATB12 = 1;
    LATBbits.LATB13 = 1;
    LATBbits.LATB14 = 0;
    LATBbits.LATB15 = 1;

    //Checks if a button is being pressed
    ejn_wait_1us();
    if(PORTAbits.RA3 == 0){
        myChar = '7';
    }
    if(PORTAbits.RA2 == 0){
        myChar = '8';
    }
    if(PORTAbits.RA1 == 0){
        myChar = '9';
    }
    if(PORTAbits.RA0 == 0){
        myChar = 'C';
    }


    //Sets row 5 to low
    LATBbits.LATB12 = 1;
    LATBbits.LATB13 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 0;

    //Checks if a button is being pressed
    ejn_wait_1us();
    if(PORTAbits.RA3 == 0){
        myChar = '*';
    }
    if(PORTAbits.RA2 == 0){
        myChar = '0';
    }
    if(PORTAbits.RA1 == 0){
        myChar = '#';
    }
    if(PORTAbits.RA0 == 0){
        myChar = 'd';
    }
    
    return myChar;
    
}


