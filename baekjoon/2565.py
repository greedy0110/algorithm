# A 전봇대 위치를 index, 연결된 B 전봇대 위치를 value 로 size 500인 arr에 배치한다.
arr = [0] * 500
N = int(input())
for _ in range(N):
    A, B = map(int, input().split())
    arr[A-1] = B

# LIS 를 구한다.
dp = [0] * 501

for i in range(500):
    # dp[i]: i를 끝으로 하는 lis
    mx_dp = 0
    for j in range(i):  # dp[0..i-1] 중에 arr[j] < arr[i] 인 dp[j] 중 최댓값 + 1
        if arr[i] == 0 or arr[j] == 0:
            continue
        if arr[j] < arr[i]:
            mx_dp = max(mx_dp, dp[j])
    dp[i] = mx_dp + 1

lis = max(dp)

# 전깃줄 갯수 - LIS 를 출력한다.
print(N - lis)
