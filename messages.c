/**
* Message module source code
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis - 28803714
* @date 11-oct-2018
*
* @brief This module provides simple methods used to display messages to the
*        player
*/


// Including used modules
#include "messages.h"
#include "tinygl.h"


/**
* Showing the welcome text on the board
*/
void show_welcome(void) {
    tinygl_text("WELCOME TO PONG");
}


/**
* Displaying a passed ball speed on the ledmat
* @param The index to the speed to display
*/
void show_speed(uint8_t index) {
    // Displaying a speed dependent on the passed index
    switch (index) {
        case 0 :
            tinygl_text(EASY);
            break;
        case 1 :
            tinygl_text(MEDIUM);
            break;
        case 2 :
            tinygl_text(HARD);
            break;
        default :
            break;
    }
}


/**
* Showing text indicating a win on the board
*/
void show_won(void) {
    tinygl_text("YOU WON!! :)  PRESS TO RESTART");
}


/**
* Showing text indicating a loss on the board
*/
void show_lost(void) {
    tinygl_text("YOU LOST :(   PRESS TO RESTART");
}
