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
void A_load(int map[15][15], Point A);


// B 下棋
void B_load(int map[15][15], Point B);


// 防止有人将棋子下到非空白位置
bool reload(Point i, int map[15][15]);


bool gameOver(int map[15][15]);


#endif