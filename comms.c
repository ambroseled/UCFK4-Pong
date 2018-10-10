#include "ir_uart.h"
#include "comms.h"


/**
* Intialising the communications for the game
*/
void comms_init(void) {
    ir_uart_init();
}


/**
* Sends a code to start the game to the other board
*/
uint8_t send_start(void) {
    if (ir_uart_write_ready_p()) {
        ir_uart_putc(START_CODE);
        return 1;
    } else {
        return 0;
    }
}


/**
* Sending a code to the other board informing it that it won the game
*/
uint8_t send_won(void) {
    if (ir_uart_write_ready_p()) {
        ir_uart_putc(WIN_CODE);
        return 1;
    } else {
        return 0;
    }
}


/**
* Sends the ball to the other board
*/
uint8_t send_ball(Ball ball) {
    if (ir_uart_write_ready_p()) {
        ir_uart_putc(BALL_CODE);
        //TODO Need to send ball postion here
        return 1;
    } else {
        return 0;
    }
}


/**
*
*/
Data receiveData(void) {
    uint8_t message;
    Data dataReceived = {EMPTY, 0};

    if (ir_uart_read_ready_p) {
        message = ir_uart_getc();

        if (message = WIN_CODE) {
            dataReceived.data_type = message;
            dataReceived.ball = ir_uart_getc();
        } else if (message = BALL_CODE) {
            dataReceived.data_type = message;

        } else if (message = START_CODE) {
            dataReceived.data_type = message;
        }
    }
    return dataReceived;
}
