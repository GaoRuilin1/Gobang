// body.cpp

#include <iostream>
#include <random>
#include <time.h>
#include "body.h"
using namespace std;


// Function: print the whole board.
// No input.
// Output: the whole board.
void print(int map[8][8]){
    for (int y = 0; y < 8; y ++) {
        cout << " ";
        for (int x = 0; x < 8; x ++) {
            if (map[y][x] == 0) cout << "_ ";
            if (map[y][x] == 1) cout << "x ";
            if (map[y][x] == 2) cout << "o ";
        }
        cout << endl;
    }
};


// A 下棋
void A_load(int map[8][8], Point A);


// B 下棋
void B_load(int map[8][8], Point B);

// Function: check if 棋子下到非空白位置
// 防止有人将棋子下到非空白位置
bool reload(Point i, int map[8][8]);


// Function: check if the game is over.
// Input: a board
// Output: 
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


void print_Rules_intro(){
}


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

    if (AB == 0) map[y][x] = 1;
    else map[y][x] = 2;

    return AB;
}


void enlarge_board(int map[8][8]);


// 把最终情况存为一个文件
void save_board(int map[8][8]);

