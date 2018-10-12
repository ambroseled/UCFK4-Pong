/**
* The game
* @team 128
* @author Ambrose Ledbrook - 79172462
* @author Josh Jarvis -
*
*/
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "paddle.h"
#include "messages.h"
#include "font3x5_1.h"
#include "font.h"
#include "button.h"
#include "comms.h"


// Defining rate constants used in the game
#define PACER_RATE 300

#define MESSAGE_RATE 15

#define BUTTON_RATE 20



/**
* This enum holds all possible states that the game can be in
*/
typedef enum {
    // Before game has started
    NOT_STARTED,
    // Game is being played
    PLAYING,
    WAITING,
    // This player won the game
    WON,
    // This player lost the game
    LOST
} Game_states;


// Variable holding the current state of the game
Game_states game_state;
uint8_t tick_count = 1;


/*
* Intialises the tinygl module used by the game
*/
void tiny_init(void) {
    // Setting up intial values of the tinygl module
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
}


/*
* Intialises the game enviroment and modules used by the game, while also
* setting the initial state
*/
void game_init(void) {
    system_init();
    tinygl_init(PACER_RATE);
    navswitch_init();
    paddle_init();
    pacer_init(PACER_RATE);
    button_init();
    tiny_init();
    game_state = NOT_STARTED;
}


/*
* Handles the movement of the paddle
*/
void paddle_task(void) {
    // Moving paddle
    paddle_move();
}


void ball_task(void) {
    //TODO Move the ball here
    //TODO Check ball collisons in other function from here
    //TODO Send ball if reaches end from here
}


/*
* Clears the display of the ledmat
*/
void clear_display(void) {
    // Clearing display
    tinygl_clear();
}


/**
* Changes the state of the game to that of the passed state
*/
void change_states(Game_states new_state) {
    // Updating the state
    game_state = new_state;
    // Checking if the current state is now WON or LOST and displaying a
    // message if so
    switch (game_state) {
        case WON :
            show_won();
            break;
        case LOST :
            show_lost();
            break;
        case PLAYING :
            //TODO Send start signal to other board
            //TODO initialise ball
            break;
        default :
            break;
    }
}


/**
* Checks if the button is pressed if so the game state is changed to PLAYING
*/
void button_task(void) {
    if (button_push_event_p(0)) {
        // Clearing the display
        clear_display();
        // Updating the game state to PLAYING
        uint8_t sent = send_start();
        if (sent) {
            change_states(PLAYING);
        }
    }
}


void check_start() {
    Data received = receiveData();
    if (received.type = START_CODE) {
        clear_display();
        change_states(PLAYING);
    }
}


void check_ir() {
    Data received = receiveData();

    switch(received.type) {
        case WIN_CODE :
            clear_display();
            change_states(WON);
            break;
        case BALL_CODE :
            //TODO change to playing state
            break;
        default :
            break;
    }
}


/*
* Runs the game
*/
int main(void) {
    game_init();
    show_welcome();
    uint8_t game_tick = 0;


    //TODO Need to handle ball hitting paddle
    //TODO Need to test and better configure the ir communications


    while(1) {
        pacer_wait();
        game_tick++;
        //TODO Check for incoming messages
        switch(game_state) {
            case WON : // Fall through to NOT_STARTED state
            case LOST : // Fall through to NOT_STARTED state
            case NOT_STARTED :
                button_task();
                check_start();
                break;
            case PLAYING :
                //TODO ball movement
                //ball_task();
                paddle_task();
                break;
            case WAITING :
                // Wait for ball or win
                check_ir();
                break;
            break;
        }
        // Updating button and navswitch at 20 hertz
        if (game_tick = PACER_RATE / BUTTON_RATE) {
            navswitch_update();
            button_update();
            game_tick = 0;
        }
        tinygl_update();
    }

}
