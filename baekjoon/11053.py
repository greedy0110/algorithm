# thanks to: https://seungkwan.tistory.com/8

N = int(input())
arr = list(map(int, input().split()))

# dp[i]: i 번째 원소를 마지막으로 하는 LIS의 길이
dp = []
for i in range(N):
    # 0..i-1 중 arr[i] 보다 작은 index 중에, dp[index]가 최대인 것 + 1
    dps = [dp[j] for j in range(i) if arr[j] < arr[i]]
    if dps:
        dp.append(max(dps)+1)
    else:
        dp.append(1)

print(max(dp))
