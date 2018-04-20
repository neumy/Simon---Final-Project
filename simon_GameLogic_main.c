/*
 * File:   simon_GameLogic_main.c
 * Author: mckenzie
 *
 * Created on April 20, 2018, 3:19 PM
 */


#include "xc.h"


void startGame(){
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
}

int main(void) {
    
    startGame();
    
    return 0;
}
