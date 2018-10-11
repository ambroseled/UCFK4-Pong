/**
*
*
*
*
*/
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "paddle.h"
#include "messages.h"
#include "fonts/font3x5_1.h"  // <-- ../fonts/font3x5_1.h
#include "font.h"
#include "button.h"
#include "task.h"


// Defining rate constants used in the game
#define PACER_RATE 500

#define MESSAGE_RATE 15

#define BUTTON_TASK_RATE 100



/**
* This enum holds all possible states that the game can be in
*/
typedef enum {
    // Before game has started
    NOT_STARTED,
    // Game is being played
    PLAYING,
    // This player won the game
    WON,
    // This player lost the game
    LOST
} Game_states;


// Variable holding the current state of the game
Game_states game_state;
uint8_t tick_count = 1;

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
* Handles the movement of the paddle
*/
void paddle_task(void) {
    // Updating navswitch
    navswitch_update();
    // Moving paddle
    paddle_move();
}


void ball_task(void) {
    //TODO Implement
}


/*
* Clears the display of the ledmat
*/
void clear_display(void) {
    // Clearing display
    tinygl_clear();
}


/**
* Checks if the button is pressed if so the game state is changed to PLAYING
*/
static void button_task(void) {
    button_update();
    if (button_push_event_p(0)) {
        // Clearing the display
        clear_display();
        // Updating the game state to PLAYING
        change_states(PLAYING);
    }
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
    }
}


/*
* Runs the game
*/
int main(void) {
    game_init();
    show_welcome();


    while(1) {
        pacer_wait();
        //TODO Check for incoming messages
        switch(game_state) {
            case WON : // Fall through to NOT_STARTED state
            case LOST : // Fall through to NOT_STARTED state
            case NOT_STARTED :
                button_task();
                break;
            case PLAYING :
                // TODO Pacer loop or task scheduler
                //TODO Ball task handled here
                //ball_task();
                paddle_task();
                break;
        }
        tinygl_update();
    }

}
