import math

N = int(input())
X = (N-1)/3

# X <= n(n-1) 를 만족하는 양의 정수 n 의 최솟값

n = (1 + math.sqrt(1 + 4*X)) / 2
print(math.ceil(n))
