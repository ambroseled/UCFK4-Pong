



#include "boing.h"
#include "tinygl.h"
#include "comms.h"


static boing_state_t ball;


void ball_init(void) {
    ball = boing_init(4, 3, DIR_E);
}


void ball_update(void) {
    tinygl_draw_point(ball.pos, 0);
    ball = boing_update(ball);
    tinygl_draw_point(ball.pos, 1);
}


void send_ball_pos(void) {
    send_ball(ball);
    tinygl_draw_point(ball.pos, 0);
}


void receiveBall(uint8_t pos) {
    ball.pos.x = 0;
    ball.pos.y = pos;
    ball.dir = DIR_W;
    ball_update();
}


uint8_t check_send(void) {
    if (ball.pos.x == 0) {
        return 1;
    } else {
        return 0;
    }
}
