black_first_row = "BWBWBWBW"
white_first_row = "WBWBWBWB"

black_first_board = [black_first_row, white_first_row] * 4
white_first_board = [white_first_row, black_first_row] * 4

N, M = (int(x) for x in input().split())
board = [[x for x in input()] for _ in range(N)]


def calc_diff(sy, sx):
    balck_ret = 0
    white_ret = 0
    for dy in range(8):
        for dx in range(8):
            if black_first_board[dy][dx] != board[sy + dy][sx + dx]:
                balck_ret = balck_ret + 1
            if white_first_board[dy][dx] != board[sy + dy][sx + dx]:
                white_ret = white_ret + 1
    return min(balck_ret, white_ret)


ret = 987654321
for y in range(N-7):
    for x in range(M-7):
        ret = min(ret, calc_diff(y, x))

print(ret)
