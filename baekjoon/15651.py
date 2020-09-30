# 생성된 수열의 순서를 지키기 위해 picked 에 순서대로 쌓아 넣는 방식을 선택
def process(arr, M, picked, count=0):
    if count == M:
        # print(" ".join([str(arr[x]) for x in picked]))
        return []

    ret = []
    for i in range(len(arr)):
        picked.append(i)
        sub = process(arr, M, picked, count + 1)
        picked.remove(i)

        if sub:
            for s in sub:
                nt = [arr[i]] + s
                ret.append(nt)
        else:
            ret.append([arr[i]])
    return ret


N, M = (int(x) for x in input().split())

arr = [x+1 for x in range(N)]

ret = process(arr, M, [])

ret = "\n".join([" ".join([str(elem) for elem in x]) for x in ret])

print(ret)
