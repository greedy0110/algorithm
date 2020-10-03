# 이 코드는 실패한 코드입니다... https://www.acmicpc.net/problem/2263

import sys

# 재귀와 메모리 사이의 상관관계는?
sys.setrecursionlimit(10**8)

N = int(input())

# BST에서 inorder는 모든 node가 정렬된 상태이다. (지금 같은 문제에서 굳이 필요없는 정보이다.)
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
# N = 100000
# inorder = [i+1 for i in range(N)]
# postorder = [i+1 for i in range(N)]


def preorder2(in_start, in_end, post_start, post_end):
    assert(in_end - in_start == post_end - post_start)

    if in_end - in_start <= 0:
        return

    root = postorder[post_end-1]
    mid = inorder.index(root)

    assert(in_start <= mid and mid < in_end)

    # inorder에서 inorder[mid] 제외
    # postorder에서 postorder[post_end - 1] 제외
    print(root, end=" ")
    # x - post_start == mid - in_start
    preorder2(in_start, mid, post_start, post_start + mid - in_start)
    # post_end -1 - x = in_end - mid - 1
    preorder2(mid+1, in_end, post_end - in_end + mid, post_end-1)


preorder2(0, N, 0, N)
print()
