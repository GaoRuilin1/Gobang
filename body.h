// BODY.h

#ifndef BODY_H
#define BODY_H


struct Point {
    int x;
    int y;
};


// 打印棋盘
void print(int map[8][8]);


// A 下棋
void A_load(int map[8][8], Point A);


// B 下棋
void B_load(int map[8][8], Point B);


// 防止有人将棋子下到非空白位置
bool reload(Point i, int map[8][8]);


int gameOver(int map[8][8]);


// 棋盘满了
bool full(int map[8][8]);


// 读文档：rule.txt
void print_Rules_intro();


// init board.
int random_init(int map[8][8]);


void enlarge_board(int map[8][8]);


// 把最终情况存为一个文件
void save_board(int map[8][8]);


#endif