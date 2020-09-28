N, M = map(int, input().split())

arr = [i + 1 for i in range(N)]


def sequence(arr, count):
    # arr 에서 count 개 만큼 골라서 수열 리스트를 반환하는 함수
    if count == 0:
        return []
    elif count == 1:
        return [[x] for x in arr]
    else:
        ret = []

        for i in range(len(arr)):
            sub_sequence = sequence(arr[i:], count - 1)
            for sub_part in sub_sequence:
                nxt = [arr[i]] + sub_part
                nxt.sort()
                ret.append(nxt)

        return ret


ret = sequence(arr, M)

print("\n".join(map(lambda x: " ".join(map(str, x)), ret)))
