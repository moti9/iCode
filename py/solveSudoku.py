# board = [
#         [9, 5, 7, 0, 1, 3, 0, 8, 4],
#         [4, 8, 3, 0, 5, 7, 1, 0, 6],
#         [0, 1, 2, 0, 4, 9, 5, 3, 7],
#         [1, 7, 0, 3, 0, 4, 9, 0, 2],
#         [5, 0, 4, 9, 7, 0, 3, 6, 0],
#         [3, 0, 9, 5, 0, 8, 7, 0, 1],
#         [8, 4, 5, 7, 9, 0, 6, 1, 3],
#         [0, 9, 1, 0, 3, 6, 0, 7, 5],
#         [7, 0, 6, 1, 8, 5, 4, 0, 9]]


def isValid(row, col, val, board):
    for i in range(9):
        if board[row][i] == val:
            return False
        if board[i][col] == val:
            return False
        nrow = (row//3)*3
        ncol = (col//3)*3
        if board[nrow + (i // 3)][ncol + (i % 3)] == val:
            return False

    return True


def solveSudoku(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                for val in range(1, 10):
                    if isValid(i, j, val, board):
                        board[i][j] = val
                        if solveSudoku(board):
                            return True
                        else:
                            board[i][j] = 0
                else:
                    return False
    return True


def printVal(self):
    for i in self:
        for j in i:
            print(j, end=" ")
        print()


def check(board):
    for i in range(9):
        for j in range(9):
            board[i][j] = 5
    # return board


def main():
    # board = [
    #     [9, 5, 7, 0, 1, 3, 0, 8, 4],
    #     [4, 8, 3, 0, 5, 7, 1, 0, 6],
    #     [0, 1, 2, 0, 4, 9, 5, 3, 7],
    #     [1, 7, 0, 3, 0, 4, 9, 0, 2],
    #     [5, 0, 4, 9, 7, 0, 3, 6, 0],
    #     [3, 0, 9, 5, 0, 8, 7, 0, 1],
    #     [8, 4, 5, 7, 9, 0, 6, 1, 3],
    #     [0, 9, 1, 0, 3, 6, 0, 7, 5],
    #     [7, 0, 6, 1, 8, 5, 4, 0, 9]]

    board = [[1,	0,	0,	0,	0,	0,	0,	0,	9],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [0,	0,	0,	0,	0,	0,	0,	0,	0],
             [9,	0,	0,	0,	0,	0,	0,	0,	1]]
    if solveSudoku(board):
        # check(board)
        printVal(board)


if __name__ == "__main__":
    main()
