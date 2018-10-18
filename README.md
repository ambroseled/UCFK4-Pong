# ENCE260 UCFK4 Assignment - Pong

A simple implementation of pong using two ucfk4. Developed by:
- `Ambrose Ledbrook | 79172462`
- `Josh Jarvis | 28803714`

## Usage
1. Set up boards in a dimely lit area close together with ir receivers and
  senders facing each other
2. In terminal navigate to the root of the group128 folder
3. Run `make clean`
4. Then run `make program` twice
5. Press the navswtich move to game difficulty selection, on either board
6. Use the navswitch to select the game difficulty
7. Confirm difficulty and start the game by pressing the navswitch
8. Use the navswitch to control your paddle
9. Play the game!!

### group128 Folder Location
- The `MakeFile` of the game relies on the `group128` folder being two directories
  down from the `drivers`, `utils` and `fonts` folders that are porvided in
  the `ence260-ucfk4` repository
- When running the game please ensure that the `group128` folder is in the
  above location

## The Game
- The goal of the game is to win by causing the other player to miss the ball
- Use your paddle to bounce the ball back onto the other players screen and
  stop it from hitting the back of your screen
- The active player will be indicated by the blue led

### Game Difficulty
- The game has 3 difficulty levels which relate to the speed of the ball
    * Easy - 1
    * Medium - 2
    * Hard - 3

### Winning / Losing the Game
- When the game is over the winner's boad will display `You Won!! :)` as well
  as the led turning on and the losing board will display `You Lost :(`
- The game menu can then be reached through a press of the navswitch from either
  board

## The Game Menu
1. The game menu first gives a greeting `Welcome to pong`
2. Then with a push of the navswitch you move on to difficulty selection
3. The navswitch can be used to cycle through the different difficulty levels
4. A push of the navswitch will confirm the difficulty and start the game

### Game Over Menu
1. A winning or losing message will be displayed
2. A push of the navswitch will again move you to difficulty selection
3. Another push of the navswitch will confirm difficulty and restart the game
