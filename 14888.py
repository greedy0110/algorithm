import math
import operator


def c14_floordiv(a, b):
    if a < 0:
        return -(-a//b)
    else:
        return a//b


ops = [operator.add, operator.sub, operator.mul, c14_floordiv]


def calc(A, op_count):
    if len(A) == 1:
        return [A[0], A[0]]

    # (최대, 최소)
    ret = [-math.inf, math.inf]

    for i in range(4):
        if op_count[i] > 0:
            oprand1 = A.pop()
            oprand2 = A.pop()
            A.append(ops[i](oprand1, oprand2))

            op_count[i] = op_count[i] - 1
            term_max, term_min = calc(A, op_count)
            op_count[i] = op_count[i] + 1

            if ret[0] < term_max:
                ret[0] = term_max
            if ret[1] > term_min:
                ret[1] = term_min

            A.pop()
            A.append(oprand2)
            A.append(oprand1)

    return ret


N = int(input())
A = list(map(int, input().split()))
A.reverse()
op_count = list(map(int, input().split()))

ret = "\n".join(map(str, calc(A, op_count)))
print(ret)
