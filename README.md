# Go Bang Pro

Team member: 
Gao Ruilin （3035772547）
Zhao Yazhou (3035772638)

Group 64 in ENGG1340 / COMP2113

## **Introduction**  

Go Bang is an abstract two-player strategy board game, traditionally played with two kinds of stones, black and white stones on a board. It is not only easy to play but can enhance thinking ability and improve intelligence. 

## **Rules**  

Players alternate turns placing a stone of their type on an empty intersection.

The winner will be the first player who build an unbroken chain of 5 stones horizontally, vertically, or diagonally.  

<img width="739" alt="截屏2021-12-02 23 03 15" src="https://user-images.githubusercontent.com/76484768/144447538-bdadcdc0-8d99-448f-bb0f-09557826f533.png">

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

#### 1. Generation of random game sets or events

The board is initialised in random: which player will play first and the first position of the piece is generated randomly.

#### 2. Data structures for storing game status

The program imply "struct" to illustrate the points and use array to store the board.


#### 3. Dynamic memory management

When the two players give the place they want to put their stones on, use dynamic varible to store the coordinates, x and y. After passing the value to the function, we delete it.

#### 4. File input/output (e.g., for loading/saving game status)

File input: at the begining of the game, a file named `rule.txt` is input for player reference.

File output: when game is over, the board will be saved in a file named `saved_board.txt`.

<img width="570" alt="截屏2021-12-02 23 01 49" src="https://user-images.githubusercontent.com/76484768/144447254-fc258152-4b9c-41f4-a320-75d01d75cb1e.png">

#### 5. Program codes in multiple files

There are files: `body.cpp`, `body.h`, `main.cpp` and `Makefile` for game generation. `body.cpp` contains the functions needed by `main.cpp`, and  `main.cpp` will include `body.cpp` to use the functions. To execute the codes, a Makefile is written.

## **Adjustments**

Because in this game their will be a strong advantage for the first player so we adjust the “Pro” opening rule. This rule restrict the first player to place the first stone at the center of the board.The second stone had to be placed at least three intersections away from the center.
