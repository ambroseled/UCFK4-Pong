/**
* Ball module header file
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* @date 13-oct-2018
*
* @brief This module header provides the ball functionality to the game to other
*        modules that require it
*/


// Defining methods and includes of the ball module if not already defined
#ifndef BALLTEST_H
#define BALLTEST_H


#include "ballTest.h"


void ball_init(void);


boing_state_t ball_update(void);


void send_ball_pos(void);


void receiveBall(uint8_t pos, uint8_t dir);


uint8_t check_send(void);


uint8_t check_lost(void);


uint8_t check_paddle(void);


#endif
