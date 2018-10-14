/**
* Ball module source code
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
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


boing_dir_t get_rand_dir(void) {
    uint8_t index = rand() % 4;
    boing_dir_t dir = DIR_NE;
    switch(index) {
        case 0 :
            dir = DIR_NE;
            break;
        case 1 :
            dir = DIR_SE;
            break;
        case 2 :
            dir = DIR_SW;
            break;
        case 3 :
            dir = DIR_NW;
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


uint8_t check_paddle(void) {
    if (ball.pos.x == 4) {
        if (check_ball(ball.pos)) {
            paddle_reverse(ball);// Reverse functon
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

void paddle_reverse (boing_state_t ball)
{
    boing_dir_t newdir[] = {DIR_S, DIR_SE, DIR_W, DIR_NE,
                            DIR_N, DIR_NW, DIR_E, DIR_SW};

    ball.dir = newdir[ball.dir];
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
*/
void receiveBall(uint8_t pos, uint8_t dir) {
    // Setting x and y postions of the ball
    ball.pos.x = 0;
    ball.pos.y = pos;
    // setting the direction of the ball
    switch (dir) {
        case NORTH :
            ball.dir = DIR_N;
            break;
        case NORTH_EAST :
            ball.dir = DIR_NE;
            break;
        case EAST :
            ball.dir = DIR_E;
            break;
        case SOUTH_EAST :
            ball.dir = DIR_SE;
            break;
        case SOUTH :
            ball.dir = DIR_S;
            break;
        case SOUTH_WEST :
            ball.dir = DIR_SW;
            break;
        case WEST :
            ball.dir = DIR_W;
            break;
        case NORTH_WEST :
            ball.dir = DIR_NW;
            break;
    }
    // Showing the ball on the ledmat
    tinygl_draw_point(ball.pos, 1);
    // Updating the postion of the ball
    // TODO Check over maybe remove
    ball_update();
}


//TODO reverse direction of ball if it hits the paddle
//TODO check if ball hits back of ledmat

/**
* Checking if the ball needs to be sent to the other board. The ball will be
* sent to the other board if its x-coordinate is 0 which is the top row of the
* ledmat. Returns 1 if the ball is to be sent and 0 otherwise.
*/
uint8_t check_send(void) {
    if (ball.pos.x == 0) {
        return 1;
    } else {
        return 0;
    }
}


void reset_ball(void) {
    ball.pos.x = 4;
    ball.pos.y = get_paddle_center();
    ball.dir = get_rand_dir();
}
