



#include "boing.h"
#include "tinygl.h"
#include "comms.h"


static boing_state_t ball;


void ball_init(void) {
    ball = boing_init(4, 3, DIR_NE);
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


void receiveBall(uint8_t pos, uint8_t dir) {
    ball.pos.x = 0;
    ball.pos.y = pos;
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
    ball_update();
}


uint8_t check_send(void) {
    if (ball.pos.x == 0) {
        return 1;
    } else {
        return 0;
    }
}
