# 생성된 수열의 순서를 지키기 위해 picked 에 순서대로 쌓아 넣는 방식을 선택
def process(arr, M, picked, count=0):
    if count == M:
        print(" ".join([str(arr[x]) for x in picked]))
        return

    for i in range(len(arr)):
        if i in picked:
            continue

        picked.append(i)
        process(arr, M, picked, count + 1)
        picked.remove(i)


N, M = (int(x) for x in input().split())

arr = [x+1 for x in range(N)]

process(arr, M, [])
