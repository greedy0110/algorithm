def matrix_mul(m1, m2):
    n = len(m1)
    ret = []
    for y in range(n):
        ret.append([])
        for x in range(n):
            elem = 0
            for a in range(n):
                elem = elem + m1[y][a] * m2[a][x]
            ret[-1].append(elem % 1000)
    return ret


def matrix_print(A):
    n = len(A)
    for y in range(n):
        for x in range(n):
            print(A[y][x], end=" ")
        print()


def process(A, B):
    if B == 1:
        return A

    if B % 2 == 0:
        half = process(A, B/2)
        return matrix_mul(half, half)
    else:
        return matrix_mul(A, process(A, B-1))


N, B = (int(x) for x in input().split())

A = [[int(x) % 1000 for x in input().split()] for _ in range(N)]

matrix_print(process(A, B))
