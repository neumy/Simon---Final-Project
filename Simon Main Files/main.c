#include "xc.h"
#include <p24Fxxxx.h>
#include "simon_keypad.h"
#include "simon_delays.h"
#include "simon_iLED.h"
#include "simon_iLED_delays.h"


// CW1: FLASH CONFIGURATION WORD 1 
#pragma config ICS = PGx1
#pragma config FWDTEN = OFF 
#pragma config GWRP = OFF
#pragma config GCP = OFF 
#pragma config JTAGEN = OFF

// CW2: FLASH CONFIGURATION WORD 2 
#pragma config I2C1SEL = PRI 
#pragma config IOL1WAY = OFF 
#pragma config OSCIOFNC = ON 
#pragma config FCKSM = CSECME
#pragma config FNOSC = FRCPLL


int main(void) {
    CLKDIVbits.RCDIV = 0; //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
    AD1PCFG = 0x9fff;
    
    initLED();
    initKeyPad();

    while(1){
        char tempChar = readKeyPadRAW();
        displayColor(tempChar);
    }
    
    return 0;
}
