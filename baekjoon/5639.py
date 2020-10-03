import sys

# 편향된 경우는...?
# 깊이가 깊어지게 되는데, 파이썬 기본은 1000 이상의 깊이를 갈 수 없다. 따라서 풀자.
sys.setrecursionlimit(20_000)


def print_postorder(preorder):
    if not preorder:
        return
    if len(preorder) == 1:
        print(preorder[0])
        return

    root = preorder[0]

    rs = len(preorder)
    for i, value in enumerate(preorder):
        if value > root:
            rs = i
            break

    print_postorder(preorder[1:rs])
    print_postorder(preorder[rs:])
    print(root)


preorder = []
# preorder = [i + 1 for i in range(10000)]
for line in sys.stdin:
    preorder.append(int(line))

print_postorder(preorder)
