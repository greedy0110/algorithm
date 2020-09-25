def process(N, r, c, base=0):
    if N == 0:
        return base

    mid = 2 ** (N-1)

    if r < mid and c < mid:
        return process(N-1, r, c, base)
    elif r < mid and c >= mid:
        return process(N-1, r, c - mid, base + 4 ** (N-1))
    elif r >= mid and c < mid:
        return process(N-1, r - mid, c, base + 2*(4 ** (N-1)))
    else:
        return process(N-1, r - mid, c - mid, base + 3*(4 ** (N-1)))


(N, r, c) = (int(x) for x in input().split())

print(process(N, r, c))
