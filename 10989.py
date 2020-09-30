import sys


def input(): return sys.stdin.readline().strip()


arr = [0] * 10001

for _ in range(int(input())):
    arr[int(input())] += 1

for i, value in enumerate(arr):
    if value != 0:
        for _ in range(value):
            print(i)
