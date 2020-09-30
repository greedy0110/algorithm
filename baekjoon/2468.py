from collections import deque
import sys


def input(): return sys.stdin.readline().strip()


n = int(input())
region = [[int(x) for x in input().split()] for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

# worst case
# n = 100
# region = [[100 for _ in range(n)] for _ in range(n)]
# visited = [[False for _ in range(n)] for _ in range(n)]


def inboard(x, y):
    return 0 <= x and x < n and 0 <= y and y < n


def process(x, y, level):
    if not inboard(x, y):
        return 0
    if visited[x][y]:
        return 0
    if region[x][y] <= level:
        return 0

    q = deque()
    q.append((x, y))
    visited[x][y] = True
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if inboard(nx, ny) and not visited[nx][ny] and region[nx][ny] > level:
                q.append((nx, ny))
                visited[nx][ny] = True

    return 1


ret = 1  # 0 일 때, 항상 1개의 영역은 존재
for level in range(1, 101):
    visited = [[False for _ in range(n)] for _ in range(n)]

    level_safe_region = 0

    for x in range(n):
        for y in range(n):
            level_safe_region = level_safe_region + process(x, y, level)

    if level_safe_region == 0:
        break

    ret = max(ret, level_safe_region)

print(ret)
