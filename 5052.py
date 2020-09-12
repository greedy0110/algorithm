import sys
import collections


def input(): return sys.stdin.readline().strip()


class Tries:
    def __init__(self):
        self._next = {}
        self._is_terminal = False

    def insert(self, word):
        if not word:
            self._is_terminal = True
            return not self._next
        else:
            key = word[0]
            if key not in self._next:
                self._next[key] = Tries()
            return not self._next[key]._is_terminal and self._next[key].insert(word[1:])


t = int(input())

for _ in range(t):
    tries = Tries()
    n = int(input())

    process = True
    for _ in range(n):
        word = input()
        if process and not tries.insert(word):
            process = False

    print("YES" if process else "NO")
