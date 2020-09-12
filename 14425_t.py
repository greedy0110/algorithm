import collections


class Trie:
    def __init__(self):
        self._next = [None] * 26
        self._is_terminal = False

    def insert(self, word):
        if not word:
            self._is_terminal = True
        else:
            key = word[0]
            if key not in self._next:
                self._next[key] = Trie()
            self._next[key].insert(word[1:])

    def find(self, word):
        if not word:
            return self._is_terminal
        else:
            key = word[0]
            if key not in self._next:
                return False
            return self._next[key].find(word[1:])


(n, m) = (int(x) for x in input().split())

trie = Trie()
for word in [input() for _ in range(n)]:
    trie.insert(word)

cnt = 0
for word in [input() for _ in range(m)]:
    if trie.find(word):
        cnt = cnt + 1

print(cnt)
