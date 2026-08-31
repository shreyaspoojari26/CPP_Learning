// SIMPLE TIC TAC TOE GAME

#include <iostream>
using namespace std;

void displayBoard(char board[])
{
    cout << "\n";

    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;

    cout << "\n";
}

bool checkWin(char board[], char player)
{
    if (board[0] == player && board[1] == player && board[2] == player)
        return true;

    if (board[3] == player && board[4] == player && board[5] == player)
        return true;

    if (board[6] == player && board[7] == player && board[8] == player)
        return true;

    if (board[0] == player && board[3] == player && board[6] == player)
        return true;

    if (board[1] == player && board[4] == player && board[7] == player)
        return true;

    if (board[2] == player && board[5] == player && board[8] == player)
        return true;

    if (board[0] == player && board[4] == player && board[8] == player)
        return true;

    if (board[2] == player && board[4] == player && board[6] == player)
        return true;

    return false;
}

int main()
{
    char board[9];
    char player;
    int position;
    char again;

    do
    {
        // Create board
        for (int i = 0; i < 9; i++)
        {
            board[i] = '1' + i;
        }

        player = 'X';

        for (int turn = 0; turn < 9; turn++)
        {
            displayBoard(board);

            cout << "Player " << player << ", enter position (1-9): ";
            cin >> position;

            position--;

            if (position < 0 || position > 8 ||
                board[position] == 'X' ||
                board[position] == 'O')
            {
                cout << "Invalid move! Try again.\n";
                turn--;
                continue;
            }

            board[position] = player;

            if (checkWin(board, player))
            {
                displayBoard(board);
                cout << "Player " << player << " wins!\n";
                break;
            }

            if (turn == 8)
            {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing!\n";

    return 0;
}
