#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "paddle.h"
#include "welcome.h"
#include "fonts/font3x5_1.h"
#include "font.h"
#include "button.h"


#define PACER_RATE 500
#define MESSAGE_RATE 10


typedef enum {
    // Before game has started
    NOT_STARTED,
    // Game is being played
    PLAYING,
    // Game is over
    GAME_OVER,
} game_states;


game_states game_state;


/*
* Intialises the game enviroment and modules osed by the game
*/
void game_init(void) {
    system_init();
    tinygl_init(PACER_RATE);
    navswitch_init();
    paddle_init();
    pacer_init(PACER_RATE);
    button_init();
    game_state = NOT_STARTED;
}


/*
* Intialises the tinygl module used by the game
*/
void tiny_init(void) {
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
void clearDisplay(void) {
    // Clearing display
    tinygl_clear();
}


/*
* Displays a winning message to the player
*/
void displayWin(void) {
    clearDisplay();
    // Displaying message to player
    tinygl_text("YOU WON!!");
}


/*
* Displays a losing meesage to the player
*/
void displayLoss(void) {
    clearDisplay();
    // Displaying message to player
    tinygl_text("YOU LOST :(");
}


/*
* Runs the game
*/
int main(void) {
    game_init();
    tiny_init();
    //TODO Sort y this is an implict declaration
    show_welcome();


    while(1) {
        pacer_wait();

        if (game_state == NOT_STARTED) {
            button_update();
            if (button_push_event_p(0)) {
                clearDisplay();
                game_state = PLAYING;
            }
        } else if (game_state == PLAYING) {

            //TODO Ball task handled here
            //ball_task();
            paddle_task();
        } else {
            //TODO Variable that is shared that shows who won
            //TODO Change to a re-play message and wait for button press
        }

        tinygl_update();
    }
}
