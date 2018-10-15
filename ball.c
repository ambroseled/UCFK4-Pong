/**
* Ball module source code
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis - 28803714
* @date 13-oct-2018
*
* @brief This module provides the ball functionality to the game through the use  of
*        the provided api module boing. It includes methods to intialise, update,
*        send, receive and check collisons for the ball.
*/


// Including modules used in this module
#include "boing.h"
#include "tinygl.h"
#include "comms.h"
#include "paddle.h"
#include <stdlib.h>


// boing_state_t variable which holds the postion and direction of the ball
static boing_state_t ball;


/**
* Generates a random value between 0 and 1 which corresponds to the directions
* North west and North east. This is used to make the ball seem more random.
* @return A random boing_dir_t which is either DIR_NW, DIR_SW
*/
boing_dir_t get_rand_dir(void) {
    // Generating number
    uint8_t index = rand() % 2;
    boing_dir_t dir = DIR_NE;
    // Getting direction from index
    switch(index) {
        case 0 :
            dir = DIR_NW;
            break;
        case 1 :
            dir = DIR_SW;
            break;
    }
    return dir;
}


/**
* Intialising the state and postion of the ball
*/
void ball_init(void) {
    ball = boing_init(4, 3, get_rand_dir());
}


/**
* Updating the postionoof the ball through the use of the boing_update method
*/
void ball_update(void) {
    // Removing current ball from ledmat
    tinygl_draw_point(ball.pos, 0);
    // Updating ball postion
    ball = boing_update(ball);
    // showing ball in its new postion
    tinygl_draw_point(ball.pos, 1);
}


/**
* Swithcing the direction of the ball when it hits the paddle
*/
void paddle_reverse (void)
{
  switch(ball.dir) {
    case DIR_SE :
      ball.dir = DIR_SW;
      break;
    case DIR_NE :
      ball.dir = DIR_NW;
      break;
    default :
      break;
  }
}


/**
* Reversing the direction os the ball.
*/
void ball_reverse(void) {
    // Removing current ball from ledmat
    tinygl_draw_point(ball.pos, 0);
    // Updating ball postion
    ball = boing_reverse(ball);
    // showing ball in its new postion
    tinygl_draw_point(ball.pos, 1);
}


/**
* Used to check if the ball has hit the paddle. Also handling the ball
* bouncing off the paddle.
* @return 0 if ball is on back of screen 1 otherwise
*/
uint8_t check_paddle(void) {
    // Checking the ball is on the bottom layer of the ledmat
    if (ball.pos.x == 4) {
        // Checking if the ball is within the paddle
        if (check_ball(ball.pos)) {
            return 1;
        } else {
            // Ball is not within the paddle and the game is over
            return 0;
        }
        // Checking if the ball is one layer above the paddle
    } else if (ball.pos.x == 3){
        // Checking edge cases where the ball hits the side of the paddle
        if (((paddle.left.y + 1) == ball.pos.y) && ball.dir == DIR_SE) {
            ball_reverse();
        } else if (((paddle.right.y - 1) == ball.pos.y) && ball.dir == DIR_NE) {
            ball_reverse();
        }
        // Checking if ball is over the paddle
        if (check_ball(ball.pos)) {
            paddle_reverse();
        }
    }
    return 1;
}


/**
* Sending the postion and direction of the ball to the other board over
* through the use of the comms module.
*/
void send_ball_pos(void) {
    // Sending the ball
    send_ball(ball);
    // Removing the ball from the ledmat
    tinygl_draw_point(ball.pos, 0);
}


/**
* Processing a ball that was received from the other board. Takes a y-coordinate
* and a direction and updates the ball to match.
* @param pos the y coordinate received for the ball
* @param dir the direction received for the ball
*/
void receiveBall(uint8_t pos, uint8_t dir) {
    // Setting x and y postions of the ball
    ball.pos.x = 0;
    ball.pos.y = pos;
    // setting the direction of the ball
    switch (dir) {
        case NORTH_EAST :
            ball.dir = DIR_NE;
            break;
        case EAST :
            ball.dir = DIR_E;
            break;
        case SOUTH_EAST :
            ball.dir = DIR_SE;
            break;
    }
    // Showing the ball on the ledmat
    tinygl_draw_point(ball.pos, 1);
}



/**
* Checking if the ball needs to be sent to the other board. The ball will be
* sent to the other board if its x-coordinate is 0 which is the top row of the
* ledmat.
* @return 1 if the ball is to be sent 0 otherwise
*/
uint8_t check_send(void) {
    // Checking if send conditions are met
    if (ball.pos.x == 0 && (ball.dir == DIR_W || ball.dir == DIR_SW || ball.dir == DIR_NW)) {
        return 1;
    } else {
        return 0;
    }
}


/**
* Resetting the postion of the ball to default. Used when the game is restarted
*/
void reset_ball(void) {
    ball.pos.x = 4;
    // Getting center postion of the paddle
    ball.pos.y = get_paddle_center();
    // Getting random direction
    ball.dir = get_rand_dir();
}
