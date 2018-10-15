/**
* Game module header file
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* @date 12-oct-2018
*
* @brief This module header provides the constants and types used by the game
*        module.
*/


// Defining constants and typedefs used by the game module
#ifndef GAME_H
#define GAME_H


// Defining rate constants used in the game
#define PACER_RATE 300
#define MESSAGE_RATE 15
#define BUTTON_RATE 300 //TODO Check/change
#define BALL_RATE 70
<<<<<<< HEAD
#define EASY 90
#define MEDIUM 55
#define HARD 35
=======
#define EASY 70
#define MEDIUM 75
#define HARD 55
>>>>>>> 7fac38fa3d7fd12494bac5b0275db30b8bd6ad8f


/**
* This enum holds all possible states that the game can be in
*/
typedef enum {
    // Game is either over or hasn't started
    NOT_STARTED,
    // When in game menu
    MENU,
    // Game is being played
    PLAYING,
    // Waiting for the ball to be sent back from the other board
    WAITING
} Game_states;


// Static variable holding values used to run the game
static Game_states game_state;
static uint8_t speed_index = 0;
static uint8_t ball_speed = EASY;


#endif
