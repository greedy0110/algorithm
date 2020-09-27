N = int(input())

table = [[int(x) for x in input().split()] for _ in range(N)]

ret = []
for i in range(N):
    ith = 1

    for j in range(N):
        if i == j:
            continue

        iw, ih = table[i]
        jw, jh = table[j]

        if jw > iw and jh > ih:
            ith = ith + 1

    ret.append(str(ith))

print(" ".join(ret))
