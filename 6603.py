import sys


def input(): return sys.stdin.readline().strip()


def comb(S, n):
    ret = []
    if n > len(S):
        return ret
    if n == 1:
        for i in S:
            ret.append([i])
    elif n > 1:
        for i in range(len(S) - n + 1):
            for temp in comb(S[i+1:], n - 1):
                temp.insert(0, S[i])
                ret.append(temp)

    return ret


while True:
    pars = [int(x) for x in input().split()]
    k = pars[0]

    if k == 0:
        break

    S = pars[1:]

    print("\n".join([" ".join([str(x) for x in comb_list])
                     for comb_list in comb(S, 6)]))
    print()
