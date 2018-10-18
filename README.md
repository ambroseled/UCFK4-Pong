# ENCE260 UCFK4 Assignment - Pong

A simple implementation of pong using two ucfk4. Developed by:
- `Ambrose Ledbrook | 79172462`
- `Josh Jarvis | 28803714`

## Usage
1. Set up boards in a dimely lit area close together with ir receivers and
  senders facing each other
2. In terminal navigate to the root of the group128 folder
3. Run `make clean program` once for each board
4. Press the navswtich move to game difficulty selection, on either board
5. Use the navswitch to select the game difficulty
6. Confirm difficulty and start the game by pressing the navswitch
7. Use the navswitch to control your paddle
8. Play the game!!

## The Game
- The goal of the game is to win by causing the other player to miss the ball
- Use your paddle to bounce the ball back onto the other players screen and
  stop it from hitting the back of your screen
- The active player will be indicated by the blue led

### Game Difficulty
- The game has 3 different difficulty levels
    * Easy - 1
    * Medium - 2
    * Hard - 3

### Winning / Losing the Game
- When the game is over the winner's boad will display `You Won!! :)` as well
  as the led turning on and the losing board will display `You Lost :(`
- The game can then be restarted by pressing the navswitch and then re-selecting
  a difficulty

## The Game Menu
1. The game menu first gives a greeting `Welcome to pong`
2. Then with a push of the navswitch you move on to difficulty selection
3. Once difficulty is confirmed through a push of the navswitch the game will
   start

### Game Over Menu
1. A winning or losing message will be displayed
2. A push of the navswitch will again move you to difficulty selection
3. Another push of the navswitch will confirm difficulty and restart the game
