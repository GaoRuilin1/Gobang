// BODY.h

#ifndef BODY_H
#define BODY_H


struct Point {
    int x;
    int y;
};


// Function: print the whole board.
// No input.
// Output: the whole board.
void print(int map[15][15]);


// Function: get the position player A chooses, load it to the board
// Input: A postison, the board
// No output while change the board
void A_load(int map[15][15], Point *A);


// Function: get the position player B chooses, load it to the board
// Input: B postison, the board
// No output while change the board
void B_load(int map[15][15], Point *B);


// Input: board, the position to check.
// Output: 
// Function: check if 5 pieces in same row, column or diagonal lines.
bool formConsecutive5(int board[15][15], int row, int col);


// Function: check if the game is over.
// Input: a board
// Output: whether game over
bool gameOver(int map[15][15]);


// Function: chaeck if the board is full
// Input: a board
// Output: whether the board is full
bool full(int map[15][15]);


// Function: read and print the rule from the file: "rule.txt".
// No input, while read a file
// No output, while print the text in the file "rule.txt"
void print_Rules_intro();


// Function: init the board, randomly decide which palyer should go first and the position of the first piece.
// Input: an empty board
// Output: which palyer play first. if AB = 0, A first, else, B first.
int random_init(int map[15][15]);


// Input: the final situation board
// Output: a saved board in the file "saved_board.txt"
// Function: store the final board into a file named as "saved_board.txt"
void save_board(int map[15][15]);


#endif
