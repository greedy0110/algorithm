cached = [[-1] * 101 for _ in range(10)]

# 계단 수 숫자, 시작 숫자, 뒤에 남은 숫자.


def stairs(start_num, remain):
    if remain == 0:
        return 1

    if cached[start_num][remain] != -1:
        return cached[start_num][remain]

    ret = 0
    if start_num > 0:
        ret += stairs(start_num - 1, remain - 1)
    if start_num < 9:
        ret += stairs(start_num + 1, remain - 1)
    ret %= 1_000_000_000
    cached[start_num][remain] = ret
    return ret


N = int(input())

ret = 0
for i in range(1, 10):
    ret += stairs(i, N - 1)
    ret %= 1_000_000_000

print(ret)
