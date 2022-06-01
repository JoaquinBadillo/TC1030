# Snakes & Ladders 🐍🎮
Author: Joaquín Badillo

## Game description
Snakes and ladders is a board game, in which players try to get from the first tile in the board to the last one. Players can move forward a number of tiles equal to the number they get on a dice roll, but there are some special tiles, that may move the player to another position. These special tiles are snake tiles and ladder tiles.

A snake tile punishes the player and in this version of the game it will always move the player behind 3 tiles.

A ladder tile rewards the player and in this version of the game it will move them 3 extra tiles.

The first player to reach the final tile wins; but there are only 16 turns (8 for each player) to reach that tile (the player that got the farthest will get a special mention). You may want to end the game before any of the previous two happens and you will be able to do so at the end of each even turn (so that both players can throw the dice); if you end it the player that got the farthest will be recognized as the "winner".

## Running the game
To run the game make sure you have a C++ compiler installed in your computer, the GCC compiler is a great option. Then you can compile the game using your prefered method, if you don't know how to compile (and you have the GCC compiler) you will want to move to the `src` directory and execute
```
$ g++ main.cpp -o main 
```
if it gets compiled correctly you should be able to execute
```
$ ./main
```

If your compiler does not compile correctly with that command you may need to include all the header files for it to link them correctly.
```
$ g++ main.cpp dice.hpp grid.hpp myGame.hpp player.hpp tiles.hpp -o main
```
Now you should be able to execute `$ ./main`. Otherwise check GCC was installed properly.

## Game instructions
Once the game executes you will see the instructions displayed in your terminal. Using a terminal in fullscreen mode is recommended.

Each turn a random dice will be thrown by each player and the game will move your character according to the rules of snakes and ladders. On your terminal you will see:
* The number of each turn
* To which player does the turn correspond
* The number rolled on the dice by that player
* The starting tile and the ending tile for that player
* A board, in which the tiles have a letter representing their type ([N]ormal, [L]adder, [S]nake), the number of the tile and spaces in which the players move (1 represents the first player, 2 represents the second player).

This will happen for both players and you will be asked if you want to continue or end the game. To continue press `c` or `C`, to end the game press `t` or `T`.

## Game design
The game was designed using the OOP paradigm, as this allows elements of the game to have characteristics (attributes) and functionalities (methods); such that they can interact with each other. You may want to consult the class diagram file (`"./classDiagram.pdf"`), but to summarize its contents the game has a grid and a dice, the grid is composed of tiles (class composition) and it has information about the users (class aggregation). The game itself is a class, whose methods are determined to match the rules of Snakes and Ladders which contains the board and the dice (class composition). Each of this classes has methods and attributes that are relevant to them, these includes ways access, alter and display their information; as well as particular actions they can perform (for instance players can move on the board).

## Important details
The board is constantly getting deleted and updated. In order to work as intended the program executes the command `@cls||clear` in the terminal. It seems to work on the Ubuntu Linux Distro (I'm currently using it in WSL), however I haven't checked it on other operative systems and Windows systems might have trouble with it. I hope it it works fine on this OS, if it does not work as intended I would encourage you to use WSL.