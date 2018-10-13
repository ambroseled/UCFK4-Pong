/**
* Game module header
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
*
*/


#ifndef GAME_H
#define GAME_H


// Defining rate constants used in the game
#define PACER_RATE 300

#define MESSAGE_RATE 15
//TODO Check over
#define BUTTON_RATE 300

#define BALL_RATE 50



/**
* This enum holds all possible states that the game can be in
*/
typedef enum {
    // Before game has started
    NOT_STARTED,
    // Game is being played
    PLAYING,
    // Waiting for the ball to be sent back from the other board
    WAITING,
    // This player won the game
    WON,
    // This player lost the game
    LOST
} Game_states;


// Variable holding the current state of the game
Game_states game_state;


#endif
