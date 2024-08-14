#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '0') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;

                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '0';
                    }
                }

                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9, '0'));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
