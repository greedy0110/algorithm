# 군형잡힌 BST를 간단하게 구현한 구현체
# 난수화된 우선순위를 각 입력 노드에 부여한다.
# 다음의 트리 규칙을 가지고 삽입한다.
#   부모의 우선순위는 자식의 우선 순위보다 높다. (heap의 기질)
#   왼쪽에는 부모 보다 작은 요소가, 오른쪽에는 부모 보다 큰 요소가 삽입된다. (BST의 기질)

# 구조체
import random


class Node:
    def __init__(self, key) -> None:
        self.key = key
        self.left = None
        self.right = None
        self.priority = random.randint(0, 10000)  # 난수화된 우선순위를 매긴다.

    def copy_node_value(self, new_node):
        self.key = new_node.key
        self.priority = new_node.priority


def treap_insert(root, key):
    return insert_node(root, Node(key))


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

    new_root = Node(0)
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


def print_trace(root, depth=0):
    if root is None:
        return

    if depth == 0:
        print("----Print Treap")
    print("{}[{} {}] depth: {}".format(
        "**"*depth, root.key, root.priority, depth))
    print_trace(root.left, depth+1)
    print_trace(root.right, depth+1)
    if depth == 0:
        print("----")


if __name__ == "__main__":
    root = Node(10)

    arr = [1, 2, 3, 4]
    for v in arr:
        root = treap_insert(root, v)

    print_trace(root)

    for v in [1, 2, 4]:
        root = treap_delete(root, v)
        print_trace(root)
