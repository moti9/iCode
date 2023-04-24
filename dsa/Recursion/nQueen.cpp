#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Approach 1

bool isSafe(int row, int col, int n, vector<string> board)
{
    int duprow = row, dupcol = col;

    // Upper Diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    // In same row
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }
    col = dupcol;

    // Lower Diagonal
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    // Safe place
    return true;
}

void placeQueen(int col, int n, vector<string> board, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            placeQueen(col + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

// Approach 2- Optimized Approach

void placeNQueen(int col, int n, vector<string> board, vector<bool> &leftRow, vector<bool> &upperDiag, vector<bool> &lowerDiag, vector<vector<string>> &ans)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (!leftRow[row] && !upperDiag[n - 1 + col - row] && !lowerDiag[row + col])
        {
            leftRow[row] = true;
            upperDiag[n - 1 + col - row] = true;
            lowerDiag[row + col] = true;
            board[row][col] = 'Q';
            placeNQueen(col + 1, n, board, leftRow, upperDiag, lowerDiag, ans);
            board[row][col] = '.';
            leftRow[row] = false;
            upperDiag[n - 1 + col - row] = false;
            lowerDiag[row + col] = false;
        }
    }
}

// Print All possible placing queen
void printAns(vector<vector<string>> ans)
{
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    // placeQueen(0, n, board, ans);
    vector<bool> leftRow(n), upperDiag(2 * n - 1), lowerDiag(2 * n - 1);

    placeNQueen(0, n, board, leftRow, upperDiag, lowerDiag, ans);
    printAns(ans);

    return 0;
}