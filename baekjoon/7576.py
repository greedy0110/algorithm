# https://www.acmicpc.net/problem/7576
import queue

# board[N][M]
M, N = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

# M, N = 1000, 1000
# board = [[0]*M for _ in range(N)]
# board[0][0] = 1

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


# BFS를 사용해야 한다.
def bfs():
    q = queue.Queue()

    # 1인 친구들을 모두 queue에 넣는다.
    want_size = 0
    flag = True
    for row in range(N):
        for col in range(M):
            if board[row][col] != -1:
                want_size += 1
            if board[row][col] == 1:
                q.put((row, col))
            elif board[row][col] == 0:
                flag = False

    if flag:
        return 0

    generation = 0
    cnt = 0
    while not q.empty():
        row, col = q.get()
        cnt += 1
        generation = board[row][col] - 1

        # row, col 주변에 0인 아이들을 칠해 뭐로? 자기꺼 +1로?
        for i in range(4):
            nx = row + dx[i]
            ny = col + dy[i]
            if 0 <= nx and nx < N and 0 <= ny and ny < M and board[nx][ny] == 0:
                board[nx][ny] = board[row][col] + 1
                q.put((nx, ny))

    if cnt != want_size:
        return -1

    return generation


print(bfs())
