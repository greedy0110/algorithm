import sys


def input(): return sys.stdin.readline().strip()


A, B = input().split()

print(max(int(A[::-1]), int(B[::-1])))
