N = int(input())
arr = list(map(int, input().split()))

# dp[i]: i를 마지막 요소로 하는 연속합.
dp = [arr[0]]

for i in range(1, N):
    candi = dp[-1] + arr[i]
    if candi > arr[i]:
        dp.append(candi)
    else:
        dp.append(arr[i])

print(max(dp))
