def d(n):
    ret = n
    for x in str(n):
        ret += int(x)
    return ret


field = [False] * 10001

for cstruct in range(1, 10001):
    # d(cstruct) 는 생성자 cstruct 를 가진다.
    target = d(cstruct)
    if target <= 10000:
        field[d(cstruct)] = True

for i in range(1, 10001):
    if not field[i]:
        print(i)
