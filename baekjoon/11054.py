N = int(input())
arr = list(map(int, input().split()))

# LIS 를 다 구해놓는다.
dp_lis = [0] * N
for i in range(N):
    mx_dp = 0
    for j in range(i):
        if arr[j] < arr[i]:
            mx_dp = max(mx_dp, dp_lis[j])
    dp_lis[i] = mx_dp + 1

# LDS 를 다 구해놓는다.
dp_lds = [0] * N
for i in range(1, N+1):  # -1 부터 출발하자.
    mx_dp = 0
    for j in range(1, i):  # -1 부터 출발한다.
        if arr[-j] < arr[-i]:
            mx_dp = max(mx_dp, dp_lds[N - j])
    dp_lds[N - i] = mx_dp + 1

# i 지점에 대해서, LIS[i] + LDS[i] - 1 을 한다.
dp_bi = [dp_lis[i] + dp_lds[i] - 1 for i in range(N)]

# 최댓값을 구한다.
# 출력한다.
print(max(dp_bi))
