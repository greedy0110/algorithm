# 생성된 수열의 순서를 지키기 위해 picked 에 순서대로 쌓아 넣는 방식을 선택

# return: list of set
def process(arr, M, picked, count=0):
    if count == M:
        # print(" ".join([str(arr[x]) for x in picked]))
        return []

    ret = []
    for i in range(len(arr)):
        if i in picked:
            continue

        picked.append(i)
        sub = process(arr, M, picked, count + 1)
        picked.remove(i)

        if sub:
            for s in sub:
                nt = [arr[i]] + s
                nt.sort()
                ret.append(nt)
        else:
            ret.append([arr[i]])
    return ret


N, M = (int(x) for x in input().split())

arr = [x+1 for x in range(N)]

comb = process(arr, M, [])

comb.sort()
ret = [" ".join(map(str, comb[0]))]
for i in range(1, len(comb)):
    if comb[i] != comb[i-1]:
        ret.append(" ".join(map(str, comb[i])))

print("\n".join(ret))
