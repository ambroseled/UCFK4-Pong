/**
   Comms module source code
   @team 128
   @author Ambrose Ledbrook - 79172462
   @author Josh Jarvis - 28803714
   @date 09-oct-2018

   @brief This module provides the ir communication functionality used by the
          game to communicate between the two boards.
*/


// Including modules used for the communication
#include "ir_uart.h"
#include "comms.h"
#include "boing.h"


/**
   Intialising the communications for the game
*/
void comms_init(void) {
    ir_uart_init();
}


/**
   Sends a code to start the game to the other board
*/
void send_start(void) {
    ir_uart_putc(START_CODE);
}


/**
   Sending a code to the other board informing it that it won the game
*/
void send_won(void) {
    ir_uart_putc(WIN_CODE);
}


/**
   Takes a boing_dir_t of the ball and converts it to a direction code to be
   sent to the other board.
   @param ball_dir the boing_dir_t of the ball
   @return A uint8_t code to send corresponding to the passed boing_dir_t
*/
uint8_t get_dir(boing_dir_t ball_dir) {
    uint8_t to_send = 0;
    // Finding what direction was passed
    switch (ball_dir) {
        case DIR_SW :
            to_send = NORTH_EAST;
            break;
        case DIR_W :
            to_send = EAST;
            break;
        case DIR_NW :
            to_send = SOUTH_EAST;
            break;
        default :
            break;
    }
    // Returning the direction code to be sent
    return to_send;
}


/**
   Sends the ball to the other board, first a BALL_CODE is sent which is then
   followed by the y-coordinate and then direction of the ball.
   @param The game ball
*/
void send_ball(boing_state_t ball) {
    // Sending a BALL_CODE
    ir_uart_putc(BALL_CODE);
    // Sending the ball y-coordinate
    ir_uart_putc(ball.pos.y);
    // Sending the balls direction
    ir_uart_putc(get_dir(ball.dir));
}


/**
   Reciving data from the other board, returns the data received in the form of
   a Data struct variable, which holds the type of data that was received as well
   as a ball y-coordinate and drection if a ball was received.
   @return The data received for the other board
*/
Data receiveData(void) {
    // Initializing variable used to receive data
    Data dataReceived = {0, 0, 0};
    // Checking if ready to recieve data
    if (ir_uart_read_ready_p()) {
        // Receiving data into the dataReceived variable
        dataReceived.type = ir_uart_getc();
        // Checking if a ball has been recived
        if (dataReceived.type == BALL_CODE) {
            // Getting the y-coordinate and direction of the ball
            dataReceived.ball_pos = ir_uart_getc();
            dataReceived.ball_dir = ir_uart_getc();
        }
        if (dataReceived.type == SPEED_CODE) {
            dataReceived.ball_pos = ir_uart_getc();
        }
    }
    // Returning the data that was received
    return dataReceived;
}


/**
   Sending the chosen ball speed to the other board
   @param The speed of the ball
*/
void send_speed(uint8_t speed) {
    // Sending SPEED_CODE
    ir_uart_putc(SPEED_CODE);
    // Sending the ball speed
    ir_uart_putc(speed);
}
