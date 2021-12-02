// BODY.h

#ifndef BODY_H
#define BODY_H


struct Point {
    int x;
    int y;
};


// 打印棋盘
void print(int map[15][15]);


// A 下棋
void A_load(int map[15][15], Point *A);


// B 下棋
void B_load(int map[15][15], Point *B);

bool formConsecutive5(int board[15][15], int row, int col);


bool gameOver(int map[15][15]);


// 棋盘满了
bool full(int map[15][15]);


// 读文档：rule.txt
void print_Rules_intro();


// init board.
int random_init(int map[15][15]);


void enlarge_board(int map[15][15]);


// 把最终情况存为一个文件
void save_board(int map[15][15]);


#endif
