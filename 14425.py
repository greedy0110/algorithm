n, m = (int(x) for x in input().split())

target = set(input() for _ in range(n))

cnt = 0
for _ in range(m):
    word = input()
    if word in target:
        cnt = cnt + 1

print(cnt)
