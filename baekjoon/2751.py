# import random
import math
import sys


def input(): return sys.stdin.readline().strip()


# arr [start, mid) 정렬된 배열 일 때
# arr [mid, end) 정렬된 배열 일 때
# 이 함수가 종료되면 arr [start, end) 영역은 정렬된 상태가 된다.


def merge(arr, start, mid, end):
    # 병합한다.
    left = arr[start:mid] + [math.inf]
    right = arr[mid:end] + [math.inf]
    i = 0
    j = 0

    for k in range(start, end):
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1

# 이 함수가 종료되면 arr [start, end) 영역은 정렬된 상태가 된다.


def merge_sort(arr, start, end):
    # 기저 케이스
    if end - start <= 1:
        return

    mid = (end + start) // 2

    # [start, mid) 영역 정렬
    merge_sort(arr, start, mid)
    # [mid, end) 영역 정렬
    merge_sort(arr, mid, end)
    # [start, end) 영역 정렬
    merge(arr, start, mid, end)


arr = [int(input()) for _ in range(int(input()))]
# arr = [random.randint(0, 5000) for _ in range(100)]
merge_sort(arr, 0, len(arr))
print("\n".join(map(str, arr)))
