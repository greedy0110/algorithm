def binary_search(A, target, left, right):
    if left > right:
        return False

    mid = (left + right) // 2
    if target > A[mid]:
        return binary_search(A, target, mid + 1, right)
    elif target < A[mid]:
        return binary_search(A, target, left, mid - 1)
    else:
        return True


N = int(input())
A = [int(ip) for ip in input().split(" ")]
M = int(input())
T = [int(ip) for ip in input().split(" ")]

A.sort()

for target in T:
    print(1 if binary_search(A, target, 0, N-1) else 0)
