# 군형잡힌 BST를 간단하게 구현한 구현체
# 난수화된 우선순위를 각 입력 노드에 부여한다.
# 다음의 트리 규칙을 가지고 삽입한다.
#   부모의 우선순위는 자식의 우선 순위보다 높다. (heap의 기질)
#   왼쪽에는 부모 보다 작은 요소가, 오른쪽에는 부모 보다 큰 요소가 삽입된다. (BST의 기질)

# 구조체
import random


class Treap:
    def __init__(self, key) -> None:
        self._key = key
        self._left = None
        self._right = None
        self._priority = random.randint(0, 10000)  # 난수화된 우선순위를 매긴다.

    def insert_node(self, new_node):
        # 우선순위를 비교한다.
        if self._priority >= new_node._priority:
            # 루트 보다 작다면? key를 비교해서 왼쪽에, 오른쪽에 둘지 결정한다.
            if self._key >= new_node._key:
                if not self._left:
                    self._left = new_node
                else:
                    self._left.insert_node(new_node)
            else:
                if not self._right:
                    self._right = new_node
                else:
                    self._right.insert_node(new_node)
        else:
            # 루트 보다 크다면? 루트의 위치에 새 노드가 들어가야 한다. 재배치가 필요하다.
            # 루트를 새 노드의 key를 기준으로 작은 트리, 큰 트리로 쪼갠다.
            left_treap, right_treap = self.split(new_node._key)

            # 루트를 새 노드로 대체한다.
            self._key = new_node._key
            self._priority = new_node._priority

            # 루트의 left, right를 앞서 구한 작은 트리, 큰 트리로 대체한다.
            self._left = left_treap
            self._right = right_treap

    def insert(self, key):
        # 새 노드를 생성한다.
        new_node = Treap(key)

        return self.insert_node(new_node)

    # return (key를 기준으로 작은 값), (key를 기준으로 큰 값)
    def split(self, key):
        dummy_root = Treap(self._key)
        dummy_root._priority = self._priority
        dummy_root._left = self._left
        dummy_root._right = self._right

        # key를 기준으로 작은 트립, 큰 트립을 나누고 반환 한다.
        # key가 루트보다 크다면, right를 쪼갠 것
        if key > self._key:  # 루트보다 큰 key
            if not self._right:  # 쪼갤 key보다 큰 원소가 없다.
                return dummy_root, None
            else:
                left_treap, right_treap = self._right.split(key)
                dummy_root._right = left_treap
                return dummy_root, right_treap
        else:  # 루트보다 작은 key
            if not self._left:  # 쪼갤 key보다 작은 원소가 없다.
                return None, dummy_root
            else:
                left_treap, right_treap = self._left.split(key)
                dummy_root._left = right_treap
                return left_treap, dummy_root

    def print_trace(self, depth=0):
        if depth == 0:
            print("----Print Treap")
        print("{}[{} {}] depth: {}".format(
            "**"*depth, self._key, self._priority, depth))
        if self._left:
            self._left.print_trace(depth+1)
        if self._right:
            self._right.print_trace(depth+1)
        if depth == 0:
            print("----")


if __name__ == "__main__":
    root = Treap(10)

    arr = [i for i in range(10000)]
    for v in arr:
        root.insert(v)

    root.print_trace()
