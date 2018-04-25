#include "xc.h"
#include "stdio.h"
#include "simon_iLED_delays.h"
#include "simon_delays.h"

void initLED(void){
    TRISBbits.TRISB11 = 0; //LED as output
    LATBbits.LATB11 = 0; //clear 
}

void write0(void){
    LATBbits.LATB11 = 1;
    wait_write0_preclear();
    LATBbits.LATB11 = 0;
    wait_write0_postclear();
}

void write1(void){
    LATBbits.LATB11 = 1;
    wait_write1_preclear();
    LATBbits.LATB11 = 0;
    wait_write1_postclear();
}

void writeColor(int r, int g, int b){
   
    int i=7;
    wait_50us();
    
    //R color generation
    for (i=7; i>=0; i--){
        if ((r>>i)&1) {
            write1();
        }
        else{
            write0();
        }
    }   
    
    //G color generation
    for (i=7; i>=0; i--){
        if ((g>>i)&1) {
            write1();
        }
        else{
            write0();
        }
    }    
    
    //B color generation
    for (i=7; i>=0; i--){
        if ((b>>i)&1) {
            write1();
        }
        else{
            write0();
        }
    }     
    
    
}

void displayColor(char keypadChar){
    char keyChar = '0';
    int reset = 0; 
    int n = 0;
    char tempChar = 0;
    
    tempChar = keypadChar;
    
    if(tempChar != 0){
        if(reset == 0){ //If color has not yet been displayed, writes color to LED
            keyChar = tempChar;
            reset = 1;

            if (keyChar == '1'){
                writeColor(255,0,0);
                for (n=0;n<250;n++){
                    wait_1ms();
                }
                writeColor(0,0,0);
            }
            if (keyChar == '*'){
                writeColor(0,128,0);
                for (n=0;n<250;n++){
                    wait_1ms();
                }
                writeColor(0,0,0);
            }
            if (keyChar == 'd'){
                writeColor(0,0,255);
                for (n=0;n<250;n++){
                    wait_1ms();
                }
                writeColor(0,0,0);
            }
            if (keyChar == 'A'){
                writeColor(255,255,0);
                for (n=0;n<250;n++){
                    wait_1ms();
                }
                writeColor(0,0,0);
            }


        }
    }
    else{ //If no value currently stored (button not being pressed), reset cleared
        reset = 0;
    }
    
}
