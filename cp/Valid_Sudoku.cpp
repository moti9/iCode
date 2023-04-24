#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isValid(int i, int j, vector<vector<char>> board, char ch)
{
    for (int x = 0; x < 9; x++)
    {
        if (board[x][j] == ch && x != i)
            return false;
        if (board[i][x] == ch && x != j)
            return false;

        int r = (x / 3) + (i / 3) * 3;
        int c = (x % 3) + (j / 3) * 3;
        if (board[r][c] == ch && i != r && j != c)
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (!isValid(i, j, board, board[i][j]))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(board);

    return 0;
}