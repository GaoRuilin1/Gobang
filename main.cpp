#include <iostream>
#include "body.h"
using namespace std;

int main() {
    int roll = 0;               // the times of giving stones
    char winner = ' ';          // the winner waiting to be decided in the game
    const int dem=15;           // the demension of our board is 15
    int board[dem][dem];
    int count=0;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = count+1;
            count++;
        }
    }

    cout << "Welcome to Gobang!" << endl;
    cout << "Rule" << endl;
    cout << "****************************************************************" << endl;

    /* give the introduction and rules about our game -- Gobang 
    by opening the introduction.txt file */
    print_Rules_intro();

    cout << "****************************************************************\n" << endl;
    cout << "Player A use x | palyer B use o" << endl;
    cout << "***The first stone will be randomly generated!***" << endl;

    // If the random position is 'o', 'x' goes first.
    if (random_init(board) == 0){
        print(board);

        cout << "B's turn" << endl;

        /* using dynamic memory to show x and y coordinate given on
        the board without using internal memory */
        Point *point = new Point;
        int px, py;

        cin >> px >> py;

        point->x = px;
        point->y = py;

        B_load(board, point);

        delete point;
    }

    while (full(board) == 0){
        if (roll % 2 == 0){         // A's turn

            print(board); 
            cout << "A's turn"<<endl;

            Point *point = new Point;
            int px, py;             // x and y coordinate

            cin >> px >> py;

            point->x = px;
            point->y = py;
            A_load(board, point); 

            delete point;

            roll+=1;                // counting times

            /*if the game end at the A , A wins*/
            if (gameOver(board) == 1){
                winner = 'A';

                cout << "A wins the game. Congratulations!" << endl;
                print(board);

                // save the final board
                save_board(board); 

                break;
            }
        }

        else{                           // B's turn
            print(board);
            cout << "B's turn"<<endl;

            Point *point = new Point;
            int px, py;                 // x and y coordinate

            cin >> px >> py;
            point->x = px;
            point->y = py;
            B_load(board, point);

            delete point;

            roll+=1;                    // counting times

            // if the game end at the B, B wins
            if (gameOver(board) == 1){
                winner = 'B';

                cout << "B wins the game. Congratulations!" << endl;
                print(board);

                save_board(board);      // save the final board

                break;
            }
        }
    }
    // if the board full without giving a winner, it is tie in this round
    if (winner == ' ') {
        cout << "There is no winner in this round. Tie." << endl;
    }

    return 0;
}
    
