/**
* Paddle module header file
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* @date 06-oct-2018
*
* @brief This module header provides the functionality of the players paddle to
*        the game module.
*/


// Defining constants, includes and typedefs used by the module
#ifndef PADDLE_H
#define PADDLE_H


// Inlcuding modules used by the paddle
#include "system.h"
#include "tinygl.h"
#include "navswitch.h"


// Defining constants used for the edges of the board
#define MAX_LEFT 6
#define MAX_RIGHT 0


/**
* This struct holds two tinygl_point_t's which hold the end points of the
* paddle
*/
typedef struct paddle {
    tinygl_point_t left;
    tinygl_point_t right;
} Paddle;


// Defining the variable to hold the paddle
Paddle paddle;


/**
* This function is used to initialize the state of the paddle.
* It sets the initial postion of the paddle
*/
void paddle_init(void);


/**
* This function shows the paddle in its current postion.
*/
void paddle_show(void);


/**
* This function moves the paddle on a NAVSWITCH_NORTH or
* NAVSWITCH_SOUTH navswitch_push_event_p.
*/
void paddle_move(void);


/**
* Checking if the passed ball postion is within the paddle.
* @param A tinygl_point_t which is the game balls postion
* @return 1 if the ball is within the paddle, 0 otherwise
*/
uint8_t check_ball(tinygl_point_t pos);


/**
* Getting the center y coordinate of the paddle
* @return The center y coordinate of the paddle
*/
uint8_t get_paddle_center(void);


#endif
