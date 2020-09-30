import math

# arr 에서 숫자 K 개를 뽑아서 중복없이 나열한다.
# return: 배열의 의 list


def sequence(arr, K):
    if K == 0:
        return []
    if K == 1:
        return [[x] for x in arr]

    ret = []
    for i in range(len(arr)):
        pick = [arr[i]]
        # 왼쪽 부터 뽑을 것이며, 중복된 숫자는 없어야 한다. 전체 리스트에 중복도 필요 없다.
        subseq = sequence(arr[i+1:], K-1)
        for sub in subseq:
            ret.append(pick + sub)

    return ret


N = int(input())

score_board = [[int(x) for x in input().split()] for _ in range(N)]


def score(group):
    total = 0
    for i in group:
        for j in group:
            if i == j:
                continue
            total = total + score_board[i][j]
    return total


arr = [i for i in range(N)]
K = N//2

ret = math.inf

for team_start in sequence(arr, K):
    team_link = [x for x in arr if x not in team_start]
    socre_start = score(team_start)
    score_link = score(team_link)

    ret = min(ret, abs(socre_start - score_link))

print(ret)
