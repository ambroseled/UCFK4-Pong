/**
* Comms module source
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
* This module provides the ir communication functionality used by the game
* to communicate between the two boards
*/


#include "ir_uart.h"
#include "comms.h"
#include "boing.h"


/**
* Intialising the communications for the game
*/
void comms_init(void) {
    ir_uart_init();
}


/**
* Sends a code to start the game to the other board
*/
void send_start(void) {
    ir_uart_putc(START_CODE);
}


/**
* Sending a code to the other board informing it that it won the game
*/
void send_won(void) {
    ir_uart_putc(WIN_CODE);
}


uint8_t get_dir(boing_dir_t ball_dir) {
    uint8_t to_send = 0;
    switch (ball_dir) {
        case DIR_N :
            to_send = NORTH;
            break;
        case DIR_NE :
            to_send = NORTH_EAST;
            break;
        case DIR_E :
            to_send = EAST;
            break;
        case DIR_SE :
            to_send = SOUTH_EAST;
            break;
        case DIR_S :
            to_send = SOUTH;
            break;
        case DIR_SW :
            to_send = SOUTH_WEST;
            break;
        case DIR_W :
            to_send = WEST;
            break;
        case DIR_NW :
            to_send = NORTH_WEST;
            break;
        default :
            break;
    }
    return to_send;
}


/**
* Sends the ball to the other board
*/
void send_ball(boing_state_t ball) {
    // Sending a BALL_CODE
    ir_uart_putc(BALL_CODE);
    ir_uart_putc(ball.pos.y);
    ir_uart_putc(get_dir(ball.dir));
}


/**
* Reciving data from the other board
*/
Data receiveData(void) {
    // Initializing variables used to receive data
    Data dataReceived = {0, 0, 0};
    if (ir_uart_read_ready_p()) {
        // Receiving data into the dataReceived variable
        dataReceived.type = ir_uart_getc();
        // Ball has been received

        if (dataReceived.type == BALL_CODE) {
            dataReceived.ball_pos = ir_uart_getc();
            dataReceived.ball_dir = ir_uart_getc();
        }
    }
    // Returning the data that was received
    return dataReceived;
}
