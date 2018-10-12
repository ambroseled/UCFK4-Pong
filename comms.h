/**
* Comms module header
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* This module provides the ir communication functionality used by the game
* to communicate between the two boards
*/


#ifndef COMMS_H
#define COMMS_H

#define WIN_CODE 12  // Just a random value
#define START_CODE 18 // Another random value
#define BALL_CODE 5



/**
* The data strucutre that is used to receive data from the other board
*/
typedef struct data_s {
    uint8_t type;
    uint8_t ball_pos;
    uint8_t ball_dir;
} Data;


#endif


/**
* Used to intialise the ir_uart module. Returning 1 on success and 0 on fail
*/
void comms_init(void);


/**
* Sends a start signal to the other board. Returning 1 on success and 0 on fail
*/
void send_start(void);


/**
* Sends a winning signal to the other board. Returning 1 on success
* and 0 on fail
*/
void send_won(void);


/**
* Sends a passed ball to the other board. Returning 1 on success and 0 on fail

uint8_t send_ball(Ball);
*/

/**
* Reciving data from the other board
*/
Data receiveData(void);
