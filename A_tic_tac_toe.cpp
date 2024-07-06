#include <iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int main()
{
    int player = 1, i, choice;
    char mark;
    bool playAgain = true;

    while (playAgain) {
        do {
            board();
            player = (player % 2) ? 1 : 2;

            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && square[choice] == '1' + choice - 1) {
                square[choice] = mark;
            } else {
                cout << "Invalid move ";
                player--;
                cin.ignore();
                cin.get();
            }

            i = checkwin();
            player++;
        } while (i == -1);

        board();
        if (i == 1)
            cout << "==>\aPlayer " << --player << " win ";
        else
            cout << "==>\aGame draw";

        cout << "\nDo you want to play again? (Y/N): ";
        char playChoice;
        cin >> playChoice;
        if (playChoice != 'Y' && playChoice != 'y')
            playAgain = false;

        // Resetting the board for a new game
        for (int j = 1; j < 10; j++) {
            square[j] = '1' + j - 1;
        }
    }

    cout << "Thanks for playing Tic Tac Toe!\n";
    return 0;
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}