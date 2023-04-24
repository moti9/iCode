#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isValid(int row, int col, char ch, vector<vector<char>> board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == ch)
            return false;
        if (board[i][col] == ch)
            return false;

        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(i, j, ch, board))
                    {
                        board[i][j] = ch;

                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // vector<vector<char>> board(9, vector<char>(9, '.'));

    // board[0][0] = '1';
    // board[8][8] = '1';
    // board[0][8] = '9';
    // board[8][0] = '9';

    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(board);

    for (auto x : board)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}