zeros = [1, 0]
ones = [0, 1]

for _ in range(2, 41):
    zeros.append(zeros[-2] + zeros[-1])
    ones.append(ones[-2] + ones[-1])

T = int(input())
for _ in range(T):
    N = int(input())
    print(zeros[N], ones[N])
