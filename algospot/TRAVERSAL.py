def print_post(preorder: list, inorder: list):
    if not preorder or not inorder:
        return

    root = preorder[0]
    mid = inorder.index(root)

    left_inorder = inorder[:mid]
    right_inorder = inorder[mid+1:]

    left_preorder = preorder[1:len(left_inorder)+1]
    right_preorder = preorder[len(left_inorder)+1:]

    print_post(left_preorder, left_inorder)
    print_post(right_preorder, right_inorder)
    print(root, end=" ")


C = int(input())
for _ in range(C):
    N = int(input())
    preorder = input().split()
    inorder = input().split()

    print_post(preorder, inorder)
    print()
