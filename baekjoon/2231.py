N = int(input())


def process(m):
    ret = m
    for part in str(m):
        ret = ret + int(part)
    return ret


ret = 0
for m in range(1, N):
    if process(m) == N:
        ret = m
        break

print(ret)
