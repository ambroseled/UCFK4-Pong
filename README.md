# ENCE260 UCFK4 Assignment - Pong

A simple implementation of pong using two ucfk4 boards. Developed by:
- `Ambrose Ledbrook | 79172462`
- `Josh Jarvis | `

## Instructions of use
- Set up boards in a dimely lit area close together with ir receivers and
  senders facing each other
- In terminal navigate to the root of the group128 folder
- Run `make clean program` for both boards
- Press the navswtich move to game difficulty selection
- Use the navswitch to select the game difficulty
- Confirm difficulty by pressing the navswitch
- Use the navswitch to control the game
- The active player will be indicated by the blue led

## The Game
- The goal of the game is to win by causing the other player to miss the ball
- Use your paddle to bounce the ball back onto the other players screen and
  stop it from hitting the back of your screen.

## Game Difficulty
- The game difficulty relates to the ball speed
    * Easy - 70
    * Medium - 55
    * Hard - 35
