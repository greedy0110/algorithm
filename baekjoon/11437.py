# LCA(u, v) -> u,v 사이의 최소 공통 조상
# u가 v의 부모 -> u
# v가 u의 부모 -> v
# LCA(u.parent, v.parent)

N = int(input())

# root는 1, 부모는 하나. 계층 구조

relation = [[] for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())

    relation[a-1].append(b-1)
    relation[b-1].append(a-1)

# 트리를 만들고. (부모 리스트가 필요하다.)
parent = [-1] * N
parent[0] = -1


def calc_parent(index):
    if index != 0 and len(relation[index]) == 1:  # leaf 노드
        return

    # 상관 관계 있는 노드 중, 부모가 안 적힌 친구는 index를 부모로 생각한다.
    for child in relation[index]:
        if index != child and parent[child] == -1:
            parent[child] = index
            calc_parent(child)


calc_parent(0)
parent[0] = 0


def lca(u, v):
    if u == v:
        return u
    if parent[v] == u:
        return u
    if parent[u] == v:
        return v

    return lca(parent[u], parent[v])


M = int(input())

for _ in range(M):
    u, v = map(int, input().split())
    print(lca(u-1, v-1) + 1)
