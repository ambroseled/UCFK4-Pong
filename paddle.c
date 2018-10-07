/**
*
*
*
*
*/

#include "system.h"
#include "tinygl.h"
#include "navswitch.h"


#define MAX_LEFT 6
#define MAX_RIGHT 0


typedef struct paddle {
    tinygl_point_t left;
    tinygl_point_t right;
} Paddle;



static Paddle paddle;




void paddle_init(void) {
    tinygl_point_t left = tinygl_point(4, 4);
    tinygl_point_t right = tinygl_point(4, 2);
    paddle.left = left;
    paddle.right = right;
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



int main(void) {
    system_init();
    tinygl_init(500);
    navswitch_init();
    paddle_init();
    paddle_show();


    while(1) {
        navswitch_update();
        paddle_move();
        tinygl_update();
    }
}
