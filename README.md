# Go Bang Pro

Team member: Gao Ruilin （3035772547）

​                           Zhao Yazhou (3035772638)

Group 64 in ENGG1340 / COMP2113

## **Introduction**  

Go Bang is an abstract two-player strategy board game, traditionally played with two kinds of stones, black and white stones on a board. It is not only easy to play but can enhance thinking ability and improve intelligence. 

## **Rules**  

Players alternate turns placing a stone of their color on an empty intersection. Black plays first. 

The winner will be the first player who build an unbroken chain of 5 stones horizontally, vertically, or diagonally.  

## Quick start

To compilate and execute this game, please type

```makefile
make main
./main
```

To clean the generated files during the game, please type

```makefile
make clean
```

## **Features to implement**  

Requirements and our features.

1. Generation of random game sets or events

The board is initialised in random: which player will play first and the first position of the piece is generated randomly.

2. Data structures for storing game status

The program imply "struct" to illustrate the points and use array to store the board.


3. Dynamic memory management

When the two players give the place they want to put their stones on, use dynamic varible to store the coordinates, x and y. After passing the value to the function, we delete it.

4. File input/output (e.g., for loading/saving game status)

File input: at the begining of the game, a file named `rule.txt` is input for player reference.

File output: when game is over, the board will be saved in a file named `saved_board.txt`.

5. Program codes in multiple files

There are files: `body.cpp`, `body.h`, `main.cpp` and `Makefile` for game generation. `body.cpp` contains the functions needed by `main.cpp`, and  `main.cpp` will include `body.cpp` to use the functions. To execute the codes, a Makefile is written.

## **Adjustments**

Because in this game their will be a strong advantage for the first player so we adjust the “Pro” opening rule. This rule restrict the first player to place the first stone at the center of the board.The second stone had to be placed at least three intersections away from the center.

## Vision

| Vison | Description                                                  | Details                                                      |
| ----- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| V1.0  | Players can choose: `Start` before the game, `Quit` and `Surrender` during the game. At the end of the game, winner will be declared. | `Start`: If players choose `Start`, game begains. `Quit`: If players choose `Quit`, game over, no winner declared. `Surrender`: If one player choose `Surrender`, the other player will be declared as winner directly. |
| V2.0  | Players can choose: `Start` before the game, `Quit` and `Surrender`  and  `Save`  during the game. At the end of the game, winner will be declared. | `Save`: If playes choose `Save` , they could contine the saved game later. |
| V3.0  | Players can choose: `Start` , `Tutorial` before the game, `Quit` and `Surrender`  and  `Save`  during the game. At the end of the game, winner will be declared. | `Tutorial`: Players could get several tutorials from a document. |
| V4.0  | A beautiful GUI will be developed.                           |                                                              |
