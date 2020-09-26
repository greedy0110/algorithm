def sub_board(board, start_y, end_y, start_x, end_x):
    ret = []
    for y in range(start_y, end_y):
        ret.append([])
        for x in range(start_x, end_x):
            ret[-1].append(board[y][x])
    return ret


def all_same(board):
    current = board[0][0]
    for y in range(len(board)):
        for x in range(len(board)):
            if current != board[y][x]:
                return None
    return current


def process(board):
    ret = [0, 0, 0]

    is_same = all_same(board)
    if is_same != None:
        ret[is_same + 1] = 1
        return ret

    n = len(board)

    mid1 = n//3
    mid2 = 2*n//3

    for y in [0, mid1, mid2]:
        for x in [0, mid1, mid2]:
            part = process(sub_board(board, y, y + n//3, x, x + n//3))
            for i in range(3):
                ret[i] = ret[i] + part[i]
    return ret


n = int(input())
board = [[int(x) for x in input().split()] for _ in range(n)]

for x in process(board):
    print(x)
