C = int(input())

for _ in range(C):
    N = int(input())

    X = []
    Y = []
    R = []

    # i 가 j 를 포함하는가?
    def enclose(i, j):
        return R[i] > R[j] and (X[i]-X[j])**2 + (Y[i]-Y[j])**2 < (R[i]+R[j])**2

    def isDirectChild(parent, child):
        # child 는 parent 내부의 원이여야 한다.
        if not enclose(parent, child):
            return False

        for i in range(N):
            if i != parent and i != child and enclose(parent, i) and enclose(i, child):
                return False
        return True

    # i node 를 root 로 하는 트리를 받아온다.
    def getTree(i):
        # Tree = (i, children)
        ret = (i, [])

        for j in range(N):
            if isDirectChild(i, j):
                ret[1].append(getTree(j))
        return ret

    # 트리를 구성 한다.
    # 자식 성벽은 부모 성벽에 "직접" 연결되어 있다.

    for _ in range(N):
        x, y, r = map(int, input().split())
        X.append(x)
        Y.append(y)
        R.append(r)

    tree = getTree(0)

    # 구성된 트리를 사용해서 리프 노드 사이의 path 를 구한다.

    heights = [0] * N

    def getHeight(tree):
        index, children = tree
        ret = 0
        for child in children:
            ret = max(ret, getHeight(child) + 1)
        heights[index] = ret
        return ret

    getHeight(tree)

    def getMaxLeafToLeaf(tree):
        _, children = tree
        if len(children) == 0:
            return 0
        elif len(children) == 1:
            return getMaxLeafToLeaf(children[0])
        else:
            child_heights = [heights[child[0]] for child in children]
            child_heights.sort()

            # 루트를 지나는 경로
            ret = child_heights[-1] + child_heights[-2] + 2

            # 루트를 지나지 않는 경로
            for child in children:
                ret = max(ret, getMaxLeafToLeaf(child))

            return ret

    print(max(getMaxLeafToLeaf(tree), heights(tree)))
