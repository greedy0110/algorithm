# 데이터 표현은?
# 양방향 리스트?
# 그냥 배열?

# 인접한 정점에 대해서 같은 색을 칠하면 안 된다.
# 인접한 정점에 대한 정보가 있어야 하는가? ok

# 정점 x의 색을 결정하는데 관여하는 요소?
#  인접한 정점 y의 색을 다 제외해야 한다.
#  제외한 색을 칠하고 다른 요소들도 마찬가지로 칠 해서 최소 값을 취한다.

# leaf 노드는 칠할 수 있는 색 중 제일 작은 색을 칠한다.
import math

N = int(input())

relation = [[] for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())

    relation[a-1].append(b-1)
    relation[b-1].append(a-1)


cost = [0] * N


def dummy_min_cost(index):
    if len(relation[index]) == 1:
        if cost[relation[index][0]] == 1:
            return 2
        else:
            return 1

    # index를 색칠하자.
    ret = math.inf
    for cc in [1, 2, 3]:
        cost[index] = cc
        for child in relation[index]:
            ret = min(ret, cc + dummy_min_cost(child))
        cost[index] = 0

    return ret


print(dummy_min_cost(0))
