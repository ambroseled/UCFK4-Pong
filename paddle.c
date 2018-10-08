/**
* 
*
*
*
*/


#include "paddle.h"
#include "system.h"
#include "tinygl.h"
#include "navswitch.h"


static Paddle paddle;


void paddle_init(void) {
    tinygl_point_t left = tinygl_point(4, 4);
    tinygl_point_t right = tinygl_point(4, 2);
    paddle.left = left;
    paddle.right = right;
    paddle_show();
}


void paddle_show(void) {
    tinygl_draw_line(paddle.left, paddle.right, 1);
}


void paddle_move(void) {

    tinygl_draw_line(paddle.left, paddle.right, 0);

    if (paddle.right.y != MAX_RIGHT && navswitch_push_event_p(NAVSWITCH_NORTH)) {
        paddle.left.y -= 1;
        paddle.right.y -= 1;
    } else if (paddle.left.y != MAX_LEFT && navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        paddle.left.y += 1;
        paddle.right.y += 1;
    }

    paddle_show();
}


//TODO Hanlde colision with ball and paddle


void paddle_collison(void) {

}
