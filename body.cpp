// body.cpp

#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include "body.h"
using namespace std;

const int num = 15;


// Function: print the whole board.
// No input.
// Output: the whole board.
void print(int map[15][15]){
    for (int y = 0; y < 15; y ++) {
        cout << " ";

        for (int x = 0; x < 15; x ++) {
            if (map[y][x] >= 0 ) cout << "_ ";      // empty
            if (map[y][x] == -1) cout << "x ";      // player A
            if (map[y][x] == -2) cout << "o ";      // player B
        }

        cout << endl;
    }
}


// Function: get the position player A chooses, load it to the board
// Input: A postison, the board
// No output while change the board
void A_load(int map[15][15], Point *A){
    int x, y;

    x = A->x;
    y = A->y;

    map[y][x] = -1;
}


// Function: get the position player B chooses, load it to the board
// Input: B postison, the board
// No output while change the board
void B_load(int map[15][15], Point *B){
    int x, y;

    x = B->x;
    y = B->y;

    map[y][x] = -2;
}


// Input: board, the position to check.
// Output: 
// Function: check if 5 pieces in same row, column or diagonal lines.
bool formConsecutive5(int board[15][15], int row, int col){
    //row
    for(int i = 0; i < 5; i++){
        if(col - i >= 0 &&
        col - i + 4 < 15 &&
        board[row][col-i] == board[row][col-i+1] &&
        board[row][col-i] == board[row][col-i+2] &&
        board[row][col-i] == board[row][col-i+3] &&
        board[row][col-i] == board[row][col-i+4]){return 1;}
    }

    //column
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 &&
        row - i + 4 < 15 &&
        board[row-i][col] == board[row-i+1][col] &&
        board[row-i][col] == board[row-i+2][col] &&
        board[row-i][col] == board[row-i+3][col] &&
        board[row-i][col] == board[row-i+4][col]){return 1;}
    }

    // diaginal (lower left to upper right)
    for(int i = 0; i < 5; i++){
        if(row + i < 15 &&
        row + i - 4 >= 0 &&
        col - i >= 0 &&
        col - i + 4 < 15 &&
        board[row+i][col-i] == board[row+i-1][col-i+1] &&
        board[row+i][col-i] == board[row+i-2][col-i+2] &&
        board[row+i][col-i] == board[row+i-3][col-i+3] &&
        board[row+i][col-i] == board[row+i-4][col-i+4]){return 1;}
    }

    // the othe diginal 
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 &&
        row - i - 4 < 15 &&
        col - i >= 0 &&
        col - i + 4 < 15 &&
        board[row-i][col-i] == board[row-i+1][col-i+1] &&
        board[row-i][col-i] == board[row-i+2][col-i+2] &&
        board[row-i][col-i] == board[row-i+3][col-i+3] &&
        board[row-i][col-i] == board[row-i+4][col-i+4]){return 1;}
    }

    return 0;
}


// Function: check if the game is over.
// Input: a board
// Output: whether game over
bool gameOver(int map[15][15]) {
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 15; col++) 
        {
            if (formConsecutive5(map, row, col) == 1) {return 1;}
        }
    }
    return 0;
}


// Function: chaeck if the board is full
// Input: a board
// Output: whether the board is full
bool full(int map[15][15]){
    bool if_full = 1;
    for (int y = 0; y < 15; y ++) {
        for (int x = 0; x < 15; x ++) {
            if (map[y][x] > 0) if_full = 0;
        }
    }

    return if_full;
}


// Function: read and print the rule from the file: "rule.txt".
// No input, while read a file
// No output, while print the text in the file "rule.txt"
void print_Rules_intro(){
    ifstream fin;
	fin.open("rule.txt");

    if ( fin.fail() ){
		cout << "Error in file opening!" 
			<< endl;
 		exit(1);
 	}
    
    string line;

	while ( getline(fin, line) ) {
		cout << line << endl;
 	}

	fin.close();
}


// Function: init the board, randomly decide which palyer should go first and the position of the first piece.
// Input: an empty board
// Output: which palyer play first. if AB = 0, A first, else, B first.
int random_init(int map[15][15]){

    srand((unsigned)time(NULL));

    int x = (rand() % 15);
    int y = (rand() % 15);
    int AB = (rand() % 2);

    if (AB == 0) map[y][x] = -1;     // player A first
    else map[y][x] = -2;             // player B first

    return AB;
}


// Input: the final situation board
// Output: a saved board in the file "saved_board.txt"
// Function: store the final board into a file named as "saved_board.txt"
void save_board(int map[15][15]) {
    ofstream fout;

    fout.open("saved_board.txt");

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    for (int y = 0; y < 15; y ++) {
        fout << " ";

        for (int x = 0; x < 15; x ++) {
            if (map[y][x] == 0) fout << "_ ";
            if (map[y][x] == -1) fout << "x ";   // player A
            if (map[y][x] == -2) fout << "o ";   // player B
        }

        fout << endl;
    }

    fout.close();
}
