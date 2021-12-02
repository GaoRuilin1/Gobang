#include <iostream>
#include "body.h"
using namespace std;

int main() {
    int roll = 0;// the times of giving stones
    char winner = ' ';// the winner waiting to be decided in the game
    const int dem=15;// the demension of our board is 15
    int board[dem][dem];
    int count=0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = count+1;
            cout<<board[i][j]<<endl;
            count++;
        }
        
    }
    
    cout << "Welcome to Gobang!" << endl;
    cout << "Rule"<< endl;
    cout << "****************************************************************"<<endl;
    print_Rules_intro();/* give the introduction and rules about our game -- Gobang 
    by opening the introduction.txt file */
    cout << "****************************************************************"<<endl;
    cout << "player A use x | palyer B use o"<<endl;
    cout << "***The first stone will be random!***" << endl;
    if (random_init(board) == 0){/* If the random position is white, black goes first */
        cout << "B's turn"<<endl;
        print(board);
        Point *point = new Point;
        int px, py;
        cin >> px >> py;
        point->x = px;
        point->y = py;
        B_load(board, point);
        delete point;/* using dynamic memory to show the x and y coordinate given on
        the board without using internal memory */
    }
    while (full(board) == 0){
        if (roll%2 == 0){
            cout << "A's turn"<<endl;
            print(board);
            Point *point = new Point;
            int px, py;
            cin >> px >> py;
            point->x = px;
            point->y = py;
            A_load(board, point);
            delete point;
            roll+=1;
            /*if the game end at the A , A wins*/
            if (gameOver(board) == 1){

                cout << "A wins the game. Congratulations!" << endl;
                print(board);
                winner='A';
                break;
            }
        }
        else{
            cout << "B's turn"<<endl;
            print(board);
            Point *point = new Point;
            int px, py;
            cin >> px >> py;
            point->x = px;
            point->y = py;
            B_load(board, point);
            delete point;
            roll+=1;
            /*if the game end at the B , B wins*/
            if (gameOver(board) == 1){
                cout << "B wins the game. Congratulations!" << endl;
                print(board);
                winner='B';
                break;

            }
        }
    }
    // if the board full without giving a winner, it is tie in this round //
    if (winner == ' ') cout << "there is no winner in this round. Tie." << endl;
    save_board(board);// save the final result of the board and the winner into a file as a record 
    return 0;
}
    
