#include <iostream>
#include <string>
#include "body.h"
using namespace std;
int main() {
    int roll = 0;// the times of giving stones
    string winner = "";// the winner waiting to be decided in the game
    const int dem=15;// the demension of our board is 15
    int board[dem][dem];
    print_Rules_intro();/* give the introduction and rules about our game -- Gobang 
    by opening the introduction.txt file */
    print(board);// show the players the original blank board
    if (random_init(board) == 0){/* If the random position is white, black goes first */
        print(board);
        Point *point = new Point;
        int *px= new int;
        int *py= new int;
        cin >> *px;
        cin >> *py;
        point->x = *px;
        point->y = *py;
        B_load(board, point);
        delete point, px, py;/* using dynamic memory to show the x and y coordinate given on
        the board without using internal memory */
    }
    while (full(board) == 0){
        if (roll%2 == 0){

            print(board);
            Point *point = new Point;
            int *px= new int;
            int *py= new int;
            cin >> *px;
            cin >> *py;
            point->x = *px;
            point->y = *py;
            A_load(board, point);
            delete point, px, py;
            roll+=1;
            /*if the game end at the A , A wins*/
            if (gameOver(board) == 1){

                cout << "A wins the game. Congratulations!";
                winner='A';
                break;

            }
        }
        else{

            print(board);
            Point *point = new Point;
            int *px= new int;
            int *py= new int;
            cin >> *px;
            cin >> *py;
            point->x = *px;
            point->y = *py;
            B_load(board, point);
            delete point, px, py;
            roll+=1;
            /*if the game end at the B , B wins*/
            if (gameOver(board) == 1){

                cout << "B wins the game. Congratulations!";
                winner='B';
                break;

            }
        }
    }
    // if the board full without giving a winner, it is tie in this round //
    if (winner == "") cout << "there is no winner in this round. Tie.";
    save_board(board);// save the final result of the board and the winner into a file as a record 
    return 0;
}
    
