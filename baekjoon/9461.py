p = [1, 1, 1, 2, 2]

for _ in range(6, 101):
    p.append(p[-1] + p[-5])

for _ in range(int(input())):
    print(p[int(input()) - 1])
