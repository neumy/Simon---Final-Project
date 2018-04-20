/*
 * File:   simon_GameLogic_main.c
 * Author: Mckenzie Ebert
 *
 * Created on April 20, 2018, 3:19 PM
 */


#include "xc.h"


void newGame(){
    /*
     * 1. LCD Output Start -> "Welcome to Simon. Press Any Button To Start."
     * 2. Wait for a button press
     * 3. Upon button press, initialize the first game round
     * 4. Each game round, add a random value to the tracking list
     * 5. Send "Round X: Watch" message to the LCD to indicate that the user should pay attention
     * 6. Indicate to the user the values they should be memorizing by sending out the sound and light indicators 
     * 7. During the above step, ignore all user inputs
     * 8. Once step 6 is complete, send the "Begin" message to the LCD to indicate that the user should begin
     * 9. Start accepting user input.
     * 10. After each user input, check that input matches the corresponding value in the tracking list
     * 11. If the values in step 10 do not match, output the "Game Over" message to the LCD (maybe have a specific sound?). User input should no longer be accepted
     * 12. If step 11 was true, return to the "home screen". Clear all values.
     * 13. If step 11 was not true, repeat step 10.
     * 14. Once all values have been input, and they are all correct, output the "Round Complete" message to the LCD
     * 15. If user completed round 100, show the "Congratulations" message. Return to "home screen" and clear all values.
     * 16. If round 100 not complete, then start a new round.
     */
    
    //Step 1
    lcd_printStr("Welcome to Simon. Press Any Button To Start.");
    
    //Step 2
    char pressedButton = '\0'; //This should be equal to whatever is output from the keypad when no buttons have been pressed
    while(pressedButton == '\0'){
        pressedButton = getButton(); //Look to see if a button has been pressed
    }
    
    //Step 3
    int round = 1;
    int stop = 0;
    while((round <= 100) && (stop == 0)){
        stop = gameRound(round);
        round++;
    }
    
    //Step 11
    if(stop == 1){
        lcd_printStr("Game Over");
        delay(500); //Gives a chance for the user to see the Game Over message
    }else{ //Step 15
        lcd_printStr("Congratulations, You Win!");
        delay(500); //Gives the user a chance to see the message
    }
    
}

int main(void) {
    
    while(1){
        newGame();
    }
    
    return 0;
}
