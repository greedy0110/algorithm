# 냅색 문제 thanks to https://coding-all.tistory.com/25

N, K = map(int, input().split())
W = []
V = []
for _ in range(N):
    w, v = map(int, input().split())
    W.append(w)
    V.append(v)

cached = [[-1] * 101 for _ in range(100_001)]

# i: 현재 한정된 용량, j: 지금 고르려고 하는 짐, ret: 최대 가치
# i <= 100_000, j <= 100


def knap_sack(i, j):
    if j == N or i <= 0:
        return 0

    if cached[i][j] != -1:
        return cached[i][j]

    # j 스킵
    ret = knap_sack(i, j+1)
    if i >= W[j]:
        # j 가치를 취함
        ret = max(ret, knap_sack(i-W[j], j+1) + V[j])

    cached[i][j] = ret
    return ret


print(knap_sack(K, 0))
