import sys


def input(): return sys.stdin.readline().strip()


N = int(input())
arr = [int(input()) for _ in range(N)]

arr.sort()

total = 0
freq = dict()
for value in arr:
    total += value
    if value not in freq:
        freq[value] = 0
    freq[value] += 1

most_freq = max(freq.values())
ret = [value for value, frequency in freq.items() if frequency == most_freq]
ret.sort()

most_freq_value = ret[0]
if len(ret) != 1:
    most_freq_value = ret[1]

print(round(total / N))
print(arr[N//2])
print(most_freq_value)
print(arr[-1] - arr[0])
