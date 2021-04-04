# BST의 한 노드가 두 자식을 가지면

#   b
# a   c

# 이 노드의 직후원소는 left를 갖지 않고 (successor)
# 증명
# 노드의 키가 x이고 x의 successor가 left를 갖는다고 하자, successor의 키를 y, successor left의 키를 z라고 하자.
# y는 x의 successor 이므로 x < u < y를 만족하는 u는 없다.
# 따라서 z가 존재한다면, z < x여야 한다. x가 두 자식을 가지므로 왼쪽 서브트리가 존재한다. z < x이므로 z는 왼쪽 서브트리에 존재한다.
# 이는 y의 left에 z가 있다는 가정에 모순된다.

# x가 두 자식을 가지므로 xl < x < xr이 성립하고
# z < y이 성립한다.

# 이 트리에서 y는 x의 successor이므로 이 트리의 임의의 요소 u에 대해서, x < u < y를 만족하는 u는 없다.

# 직전원소는 right를 갖지 않음 (predecessor)
