one_to_nine = {1, 2, 3, 4, 5, 6, 7, 8, 9}
mid1 = 3
mid2 = 6
starts = [0, mid1, mid2]
ends = [mid1, mid2, 9]


# sub board 로부터 one_to_nine 에 없는 숫자 리스트만 반환하라.
def sub_board(board, start_y, end_y, start_x, end_x):
    ret = set()
    for y in range(start_y, end_y):
        for x in range(start_x, end_x):
            if board[y][x] != 0:
                ret.add(board[y][x])
    return one_to_nine - ret

# y, x 위치에 둘 수 있는 숫자를 배열로 반환한다.


def possible_case(board, y, x):
    py = one_to_nine - {elem for elem in board[y] if elem != 0}

    col_y = set()
    for ty in range(9):
        if board[ty][x] != 0:
            col_y.add(board[ty][x])
    px = one_to_nine - col_y

    weight_y = y // 3
    weight_x = x // 3

    pm = sub_board(board, starts[weight_y], ends[weight_y],
                   starts[weight_x], ends[weight_x])

    return py & px & pm


def print_board(board):
    for y in range(len(board)):
        print(" ".join(map(str, board[y])))


def sudoku(board):
    target = None
    for y in range(9):
        if target != None:
            break
        for x in range(9):
            if board[y][x] == 0:
                target = (y, x)
                break

    if target == None:
        print_board(board)
        return True

    ty, tx = target

    cases = possible_case(board, ty, tx)

    if not cases:
        # 스도쿠 제작 실패
        return False

    for case in cases:
        board[ty][tx] = case
        if sudoku(board):
            return True
        board[ty][tx] = 0


board = [[int(x) for x in input().split()] for _ in range(9)]

sudoku(board)
