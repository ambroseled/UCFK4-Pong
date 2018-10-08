/**
*
*
*
*
*/
#ifndef PADDLE_H
#define PADDLE_H


#define MAX_LEFT 6
#define MAX_RIGHT 0


#include "system.h"
#include "tinygl.h"
#include "navswitch.h"


typedef struct paddle {
    tinygl_point_t left;
    tinygl_point_t right;
} Paddle;


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



#endif
