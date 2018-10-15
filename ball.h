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


#include "ball.h"


/**
* Intialising the state and postion of the ball
*/
void ball_init(void);


/**
* Updating the postion of the ball through the use of the boing_update method
*/
void ball_update(void);


/**
* Sending the postion and direction of the ball to the other board over
* through the use of the comms module.
*/
void send_ball_pos(void);


/**
* Processing a ball that was received from the other board. Takes a y-coordinate
* and a direction and updates the ball to match.
* @param pos the y coordinate received for the ball
* @param dir the direction received for the ball
*/
void receiveBall(uint8_t pos, uint8_t dir);


/**
* Checking if the ball needs to be sent to the other board. The ball will be
* sent to the other board if its x-coordinate is 0 which is the top row of the
* ledmat.
* @return 1 if the ball is to be sent 0 otherwise
*/
uint8_t check_send(void);


/**
* Used to check if the ball has hit the paddle. Also handling the ball
* bouncing off the paddle.
* @return 0 if ball is on back of screen 1 otherwise
*/
uint8_t check_paddle(void);


/**
* Resetting the postion of the ball to default. Used when the game is restarted
*/
void reset_ball(void);


#endif
