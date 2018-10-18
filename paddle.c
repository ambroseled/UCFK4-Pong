/**
   Paddle module source code
   @team 128
   @author Ambrose Ledbrook - 79172462
   @author Josh Jarvis - 28803714
   @date 06-oct-2018
   @brief This module provides the functionality of the game paddle.
*/


#include "paddle.h"
#include "system.h"
#include "tinygl.h"
#include "navswitch.h"


/**
   This function is used to initialize the state of the paddle.
   It sets the initial postion of the paddle
*/
void paddle_init(void) {
    // Setting the initial postions of the paddle
    tinygl_point_t left = tinygl_point(BOTTOM_COLUMN, PADDLE_START_LEFT);
    tinygl_point_t right = tinygl_point(BOTTOM_COLUMN, PADDLE_START_RIGHT);
    // Intialising the paddle points
    paddle.left = left;
    paddle.right = right;
    // Displaying the paddle
    paddle_show();
}


/**
   This function shows the paddle in its current postion.
*/
void paddle_show(void) {
    // Drawing the paddle
    tinygl_draw_line(paddle.left, paddle.right, SHOW_PADDLE);
}


/**
   This function moves the paddle on a NAVSWITCH_NORTH or
   NAVSWITCH_SOUTH navswitch_push_event_p.
*/
void paddle_move(void) {
    // Removing current paddle
    tinygl_draw_line(paddle.left, paddle.right, HIDE_PADDLE);
    // Updating the paddle postion if the navswitch is press
    if (paddle.right.y != MAX_RIGHT && navswitch_push_event_p(NAVSWITCH_NORTH)) {
        paddle.left.y -= MOVEMENT_INCREMENT;
        paddle.right.y -= MOVEMENT_INCREMENT;
    } else if (paddle.left.y != MAX_LEFT && navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        paddle.left.y += MOVEMENT_INCREMENT;
        paddle.right.y += MOVEMENT_INCREMENT;
    }
    // Showing the paddle in its new current postion
    paddle_show();
}


/**
   Checking if the passed ball postion is within the paddle.
   @param A tinygl_point_t which is the game balls postion
   @return 1 if the ball is within the paddle, 0 otherwise
*/
uint8_t check_ball(tinygl_point_t pos) {
    if (pos.y >= paddle.right.y && pos.y <= paddle.left.y) {
        return 1;
    } else {
        return 0;
    }
}


/**
   Getting the center y coordinate of the paddle
   @return The center y coordinate of the paddle
*/
uint8_t get_paddle_center(void) {
    return (paddle.left.y + paddle.right.y) / PADDLE_WIDTH;
}
