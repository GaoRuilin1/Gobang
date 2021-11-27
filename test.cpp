#include <iostream>
#include <random>
#include <time.h>
using namespace std;


// Function: print the whole board.
// No input.
// Output: the whole board.
void print_map(int map[8][8]){
    for (int y = 0; y < 8; y ++) {
        cout << " ";
        for (int x = 0; x < 8; x ++) {
            if (map[y][x] == 0) cout << "_ ";
            if (map[y][x] == 1) cout << "x ";
            if (map[y][x] == 2) cout << "o ";
        }
        cout << endl;
    }
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

int main() {
    int map[8][8];
    int player;
    player = random_init(map);
    print_map(map);
    return 0;
}