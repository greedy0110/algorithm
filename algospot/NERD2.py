import sys
import random


class Node:
    def __init__(self, key, value) -> None:
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.priority = random.randint(0, 10000)  # 난수화된 우선순위를 매긴다.

    def copy_node_value(self, new_node):
        self.key = new_node.key
        self.value = new_node.value
        self.priority = new_node.priority


def treap_insert(root, key, value):
    return insert_node(root, Node(key, value))


def insert_node(root, new_node):
    if root is None:
        root = new_node
        return root

    # 우선순위를 비교한다.
    if root.priority >= new_node.priority:
        # 루트 보다 작다면? key를 비교해서 왼쪽에, 오른쪽에 둘지 결정한다.
        if root.key >= new_node.key:
            root.left = insert_node(root.left, new_node)
        else:
            root.right = insert_node(root.right, new_node)
    else:
        # 루트 보다 크다면? 루트의 위치에 새 노드가 들어가야 한다. 재배치가 필요하다.
        # 루트를 새 노드의 key를 기준으로 작은 트리, 큰 트리로 쪼갠다.
        left_treap, right_treap = split(root, new_node.key)

        # 루트를 새 노드로 대체한다.
        root.copy_node_value(new_node)

        # 루트의 left, right를 앞서 구한 작은 트리, 큰 트리로 대체한다.
        root.left = left_treap
        root.right = right_treap

    # key를 추가한 트립의 root를 반환한다.
    return root


def split(root, key):
    # (key를 기준으로 작은 값, key를 기준으로 큰 값)을 반환한다.
    if root is None:
        return None, None

    new_root = Node(0, 0)
    new_root.copy_node_value(root)
    new_root.left = root.left
    new_root.right = root.right

    # key를 기준으로 작은 트립, 큰 트립을 나누고 반환 한다.
    # key가 루트보다 크다면, right를 쪼갠 것
    if key > root.key:  # 루트보다 큰 key
        left_treap, right_treap = split(root.right, key)
        new_root.right = left_treap
        return new_root, right_treap
    else:  # 루트보다 작은 key
        left_treap, right_treap = split(root.left, key)
        new_root.left = right_treap
        return left_treap, new_root


def treap_delete(root, key):
    if root is None:
        return root

    if key > root.key:
        root.right = treap_delete(root.right, key)
    elif key < root.key:
        root.left = treap_delete(root.left, key)
    else:  # 해당 root가 삭제 대상이다.
        if root.left is None and root.right is None:  # leaf node이다. 그냥 삭제하자.
            del root
            return None
        elif root.left is None:  # 자식이 하나이면, 자식을 root에 카피한다.
            new_root = root.right
            del root
            return new_root
        elif root.right is None:  # 자식이 하나이면, 자식을 root에 카피한다.
            new_root = root.left
            del root
            return new_root
        else:  # 자식이 두 개면, 재배치가 필요하다.
            new_root = del_merge(root.left, root.right)
            del root
            return new_root

    # key를 삭제한 트립의 root를 반환한다.
    return root


def del_merge(left, right):
    if left is None:
        return right
    if right is None:
        return left

    # root노드를 제거할 때, left, right 기준
    assert(left.key < right.key)

    if left.priority < right.priority:
        right.left = del_merge(left, right.left)
        return right
    else:
        left.right = del_merge(left.right, right)
        return left


def lower_bound(root, key):
    # x이상인 Node중에 가장 작은 Node를 반환
    if root is None:
        return None

    if root.key == key:
        return root
    elif key > root.key:
        return lower_bound(root.right, key)
    else:  # key < root.key
        # root가 대상 일 수 있음. left가 없으면?
        if root.left is None:
            return root
        else:
            return lower_bound(root.left, key)


def nerd_delete(root, ip, iq):
    # 입력된 ip 보다 작은 key에 대해서 iq가 value보다 크면, 작은 key 값은 제거한다. 제거한 root를 반환한다.
    if root is None:
        return None

    # 입력된 ip 보다 작은 key에 대해서
    if ip < root.key:  # root, right 는 판별 대상이 아니다.
        root.left = nerd_delete(root.left, ip, iq)
        return root
    else:  # root 도 판단의 대상이 된다.
        root.left = nerd_delete(root.left, ip, iq)
        root.right = nerd_delete(root.right, ip, iq)

        if iq > root.value:  # 제거 대상.
            root = treap_delete(root, root.key)
        return root


def tree_maxinum(root):
    while root.right is not None:
        root = root.right
    return root


def predecessor(root, x):
    if x is None:
        return x
    if x.left is not None:
        return tree_maxinum(x.left)
    y = parent(root, x)
    while y is not None and x == y.left:
        x = y
        y = y.parent
    return y


def parent(root, x):
    parent = None
    while root.key != x.key:
        parent = root
        if root.key > x.key:
            root = root.left
        else:
            root = root.right
    return parent


def simple_size(root):
    if root is None:
        return 0
    else:
        return 1 + simple_size(root.left) + simple_size(root.right)


C = int(sys.stdin.readline().strip())

for _ in range(C):
    N = int(sys.stdin.readline().strip())

    cnt = 0
    root = None
    for i in range(N):
        ip, iq = map(int, sys.stdin.readline().strip().split())

        # p를 key, q를 value로 가지는 BST를 설계한다. (당연히 밸런스가 잡혀있어야 한다.)

        # 입력된 ip 보다 큰 key에 대해서 iq가 q보다 작으면, 이 입력은 무시해도 된다.
        ip_next_node = lower_bound(root, ip)
        if ip_next_node is not None and ip_next_node.value > iq:  # 무시 가능
            cnt += simple_size(root)
            continue

        # 입력된 ip 보다 작은 key에 대해서 iq가 q보다 크면, 작은 key 값은 제거한다.
        # ip_next_node의 predecessor를 찾아야 한다.
        pre = predecessor(root, ip_next_node)
        delete_list = []
        while pre is not None and pre.value <= iq:
            delete_list.append(pre.key)
            pre = predecessor(root, pre)

        for v in delete_list:
            treap_delete(root, v)

        root = treap_insert(root, ip, iq)
        # BST의 값 총 수를 반환한다.

        cnt += simple_size(root)

    print(cnt)
