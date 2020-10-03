count = [0] * 10

N = int(input())
for i in range(1, N+1):
    for elem in str(i):
        count[int(elem)] += 1
    print(*count)
