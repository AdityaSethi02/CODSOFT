#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board)
{
    for (const auto& row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board)
{
    for (const auto& row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));

    char currentPlayer = 'X';

    bool gameWon = false;
    bool draw = false;

    cout << "Tic-Tac-Toe Game\n";
    cout << "Player X starts\n";

    while (!gameWon && !draw)
    {
        cout << "Current board:\n";
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer))
            {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!\n";
            }

            else if (checkDraw(board))
            {
                draw = true;
                cout << "It's a draw!\n";
            }

            else
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        else
        {
            cout << "Invalid move! Try again.\n";
        }
    }
    cout << "Final board:\n";
    displayBoard(board);

    return 0;
}
