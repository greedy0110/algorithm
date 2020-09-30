def can_place(queens, y, x):
    for qy, qx in queens:
        if y == qy or x == qx or y-qy == x-qx or y-qy == -x+qx:
            return False
    return True


ans = 0
N = int(input())
# 직선 위, + 대각선, - 대각선
a, b, c = [False]*N, [False]*(2*N-1), [False]*(2*N-1)


# 시간 복잡도가 무침 (n**n) -> n! 으로...
# 가지 치기?


def process(sx=0):
    global ans
    if sx == N:
        ans += 1
        return

    for y in range(N):
        if not (a[y] or b[y+sx] or c[sx-y+N-1]):
            a[y] = b[y+sx] = c[sx-y+N-1] = True
            process(sx+1)
            a[y] = b[y+sx] = c[sx-y+N-1] = False


process(0)
print(ans)
