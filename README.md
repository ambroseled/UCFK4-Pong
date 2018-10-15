# ENCE260 UCFK4 Assignment - Pong

A simple implementation of pong using two ucfk4 boards. Developed by:
- `Ambrose Ledbrook | 79172462`
- `Josh Jarvis | `

## How to Play
- Set up boards in a dimely lit area close together with ir receivers and
  senders facing each other
- In terminal navigate to the root of the group128 folder
- Run `make clean program` once for each board
- Press the navswtich move to game difficulty selection
- Use the navswitch to select the game difficulty
- Confirm difficulty by pressing the navswitch
- Use the navswitch to control your paddle

## The Game
- The goal of the game is to win by causing the other player to miss the ball
- Use your paddle to bounce the ball back onto the other players screen and
  stop it from hitting the back of your screen
- The active player will be indicated by the blue led

## Game Difficulty
- The game has 3 different difficulty levels
    * Easy - 1
    * Medium - 2
    * Hard - 3

## Winning / Losing the Game
- When the game is over the winner's boad will display `You Won!! :)` as well
  as the led turning on and the losing board will display `You Lost :(`
- The game can then be restarted by pressing the navswitch and then re-selecting
  a difficulty
