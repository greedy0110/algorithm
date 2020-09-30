import sys
import collections


def input(): return sys.stdin.readline().strip()


class Trie():
    def __init__(self):
        self._next = {}
        self._end = False

    def insert(self, word):
        if not word:
            self._end = True
        else:
            key = word[0]
            if key not in self._next:
                self._next[key] = Trie()
            self._next[key].insert(word[1:])

    def algo(self, word, init=False):
        if not word:
            return 0

        next_path = word[0]  # 문제 조건상 무조건 첫 글자이다.
        if not self._end and len(self._next) == 1:
            return self._next[next_path].algo(word[1:]) + (1 if init else 0)

        return 1 + self._next[next_path].algo(word[1:])


n = int(input())
while True:
    words = [input() for _ in range(n)]

    trie = Trie()
    for word in words:
        trie.insert(word)

    cnt = 0
    for word in words:
        cnt = cnt + trie.algo(word, True)
    print("{:.2f}".format(cnt / n))  # 반 올림 해서 보여준다.

    try:
        n = int(input())
    except:
        break
