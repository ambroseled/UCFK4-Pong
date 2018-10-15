/**
* Message module header file
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis - 28803714
* @date 11-oct-2018
*
* @brief This module header provides simple methods used to display messages
*        to the player to the game module.
*/


// Defining inlcudes used by the module
#ifndef PADDLE_H
#define PADDLE_H
#define EASY "1"
#define MEDIUM "2"
#define HARD "3"


// Inlcuding the tinygl module used by the module
#include "tinygl.h"


#endif


/**
* Showing the welcome text on the board
*/
void show_welcome(void);


/**
* Showing text indicating a win on the board
*/
void show_won(void);


/**
* Showing text indicating a loss on the board
*/
void show_lost(void);


/**
* Displaying a passed ball speed on the ledmat
* @param The index to the speed to display
*/
void show_speed(uint8_t index);
