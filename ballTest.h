


#ifndef BALLTEST_H
#define BALLTEST_H

#include "boing.h"


void ball_init(void);


boing_state_t ball_update(void);


void send_ball_pos(void);


void receiveBall(uint8_t pos);


uint8_t check_send(void);


#endif
