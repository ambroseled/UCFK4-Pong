/**
* Comms module header file
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* @date 09-oct-2018
*
* @brief This module header provides the ir communication functionality to other
*        modules of the game that require it.
*/


// Defining constants and includes of the module if not already defined
#ifndef COMMS_H
#define COMMS_H


// Defining message code types and direction types used in communication
// Arbitrary values have been chosen here to represent the different types and
// directions
#define WIN_CODE 12
#define START_CODE 33
#define BALL_CODE 5
#define SPEED_CODE 3
#define NORTH 25
#define NORTH_EAST 26
#define EAST 27
#define SOUTH_EAST 28
#define SOUTH 29
#define SOUTH_WEST 30
#define WEST 31
#define NORTH_WEST 32


// Inlcuding modules used
#include "ir_uart.h"
#include "boing.h"


/**
* The data strucutre that is used to receive data from the other board. It holds
* a message type as well as a ball y-coordinate and ball direction.
*/
typedef struct data_s {
    // Message type
    uint8_t type;
    // Ball y-coordinate
    uint8_t ball_pos;
    // Ball direction
    uint8_t ball_dir;
} Data;


#endif


/**
* Intialising the communications for the game
*/
void comms_init(void);


/**
* Sends a code to start the game to the other board
*/
void send_start(void);


/**
* Sending a code to the other board informing it that it won the game
*/
void send_won(void);


/**
* Sends the ball to the other board, first a BALL_CODE is sent which is then
* followed by the y-coordinate and then direction of the ball.
*/
void send_ball(boing_state_t ball);


/**
* Reciving data from the other board, returns the data received in the form of
* a Data struct variable, which holds the type of data that was received as well
* as a ball y-coordinate and drection if a ball was received.
*/
Data receiveData(void);


/**
* Sending the chosen ball speed to the other board
*/
void send_speed(uint8_t speed);
