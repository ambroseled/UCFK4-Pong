

#ifndef COMMS_H
#define COMMS_H

#define WIN_CODE 12  // Just a random value
#define START_CODE 18 // Another random value
#define BALL_CODE 5



typedef enum {
    GAME_WON,
    BALL_POS,
    EMPTY,
    NOT_ACCEPTED
} Data_Type;


typedef stuct data_s {
    Data_Type data_type;
    uint8_t ball;
} Data;

void send_start();


void send_game_over();



#endif
