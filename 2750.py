N = int(input())
arr = [int(input()) for _ in range(N)]


def insertion_sort(arr):
    N = len(arr)
    cursor = 1
    while cursor <= N:
        # arr[:cursor] 는 정렬된 배열이라고 생각한다.
        # arr[:cursor+1] 을 정렬된 배열로 만든다.
        for j in range(cursor-1, 0, -1):
            if arr[j] > arr[j-1]:
                break
            arr[j], arr[j-1] = arr[j-1], arr[j]

        # cursor += 1 을 시킨다.
        cursor += 1


insertion_sort(arr)

print("\n".join(map(str, arr)))
