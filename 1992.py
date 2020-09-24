import sys


def input(): return sys.stdin.readline().strip()


def sub_board(board, start_y, end_y, start_x, end_x):
    ret = []
    for y in range(start_y, end_y):
        ret.append([])
        for x in range(start_x, end_x):
            ret[-1].append(board[y][x])
    return ret


def quad(board):
    local_n = len(board)

    summation = 0
    for y in range(local_n):
        for x in range(local_n):
            summation = summation + board[y][x]

    if summation == 0:
        print(0, end="")
    elif summation == local_n * local_n:
        print(1, end="")
    else:
        mid = local_n // 2
        print("(", end="")
        quad(sub_board(board, 0, mid, 0, mid))
        quad(sub_board(board, 0, mid, mid, local_n))
        quad(sub_board(board, mid, local_n, 0, mid))
        quad(sub_board(board, mid, local_n, mid, local_n))
        print(")", end="")


n = int(input())
board = [[int(x) for x in input()] for _ in range(n)]

quad(board)
print()
