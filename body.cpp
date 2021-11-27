// body.cpp

#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include "body.h"
using namespace std;


// 已经 de 完 bug
// Function: print the whole board.
// No input.
// Output: the whole board.
void print(int map[8][8]){
    for (int y = 0; y < 8; y ++) {
        cout << " ";

        for (int x = 0; x < 8; x ++) {
            if (map[y][x] == 0) cout << "_ ";
            if (map[y][x] == 1) cout << "x ";   // player A
            if (map[y][x] == 2) cout << "o ";   // player B
        }

        cout << endl;
    }
}

// A 下棋
// Function: get the position player A chooses, load it to the board
// Input: A postison, the board
// No output while change the board
void A_load(int map[8][8], Point A){
    int x, y;
    x = A.x;
    y = A.y;
    map[y][x] = 1;
}


// B 下棋
// Function: get the position player B chooses, load it to the board
// Input: B postison, the board
// No output while change the board
void B_load(int map[8][8], Point B){
    int x, y;
    x = B.x;
    y = B.y;
    map[y][x] = 2;
}



// Function: check if 棋子下到非空白位置
// 防止有人将棋子下到非空白位置
bool reload(Point i, int map[8][8]);


// Function: check if the game is over.
// Input: a board
// Output: whether game over
bool gameOver(int map[8][8]);


// Function: chaeck if the board is full
// Input: a board
// Output: whether the board is full
bool full(int map[8][8]){
    bool if_full = 1;
    for (int y = 0; y < 8; y ++) {
        for (int x = 0; x < 8; x ++) {
            if (map[y][x] == 0) if_full = 0;
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


// 已经 de 完 bug
// Function: init the board, randomly decide which palyer should go first and the position of the first piece.
// Input: an empty board
// Output: which palyer play first. if AB = 0, A first, else, B first.
int random_init(int map[8][8]){
    for (int y = 0; y < 8; y ++) {
        for (int x = 0; x < 8; x ++) {
            map[y][x] = 0;
        }
    }

    srand((unsigned)time(NULL));

    int x = (rand() % 8);
    int y = (rand() % 8);
    int AB = (rand() % 2);

    if (AB == 0) map[y][x] = 1;     // player A first
    else map[y][x] = 2;             // player B first

    return AB;
}


void enlarge_board(int map[8][8]);


// 把最终情况存为一个文件
void save_board(int map[8][8]) {
    ofstream fout;

    fout.open("saved_board.txt");

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    for (int y = 0; y < 8; y ++) {
        fout << " ";

        for (int x = 0; x < 8; x ++) {
            if (map[y][x] == 0) fout << "_ ";
            if (map[y][x] == 1) fout << "x ";   // player A
            if (map[y][x] == 2) fout << "o ";   // player B
        }

        fout << endl;
    }

    fout.close();
}

