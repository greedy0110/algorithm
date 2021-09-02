//
// Created by 신승민 on 2021/09/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

class AhoCorasick {
    struct Node {
        vi children;
        bool valid;
        int kind;

        Node() {
            children = vi(2, -1);
            valid = false;
            kind = -1;
        }
    };

public:
    vector<Node> trie;
    vi fail;
    int root;
    int cnt_kind = 0;

    int createNode() {
        Node x;
        trie.push_back(x);
        return (int) trie.size() - 1;
    }

    AhoCorasick() {
        root = createNode();
    }

    // 문제의 입력에서 p 는 모두 같은 길이일 것.
    int add(int node, const vi &p, int index) {
        if (p.size() == index) {
            if (trie[node].kind != -1) return trie[node].kind;
            trie[node].valid = true;
            trie[node].kind = cnt_kind;
            return cnt_kind++;
        }

        int &child = trie[node].children[p[index]];
        if (child == -1) child = createNode();
        return add(child, p, index + 1);
    }

    void createFail() {
        fail = vi(trie.size());
        fail[root] = root;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int next = trie[cur].children[i];
                if (next == -1) continue;
                if (cur == root) fail[next] = root;
                else {
                    int x = fail[cur];
                    while (x != root && trie[x].children[i] == -1) x = fail[x];
                    if (trie[x].children[i] != -1) x = trie[x].children[i];
                    fail[next] = x;
                }
                // 만약 찾았다면. 항상 댑스가 일정하다.
                q.push(next);
            }
        }
    }

    vi search(const vi &s) {
        vi ans(s.size(), -1);
        int node = root;
        for (int i = 0; i < s.size(); i++) {
            while (node != root && trie[node].children[s[i]] == -1) node = fail[node];
            if (trie[node].children[s[i]] != -1) node = trie[node].children[s[i]];
            if (trie[node].valid) ans[i] = trie[node].kind;
        }
        return ans;
    }
};

int to_index(char c) {
    if (c == 'o') return 0;
    if (c == 'x') return 1;
    assert(false);
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int hp, wp, hm, wm;
    cin >> hp >> wp >> hm >> wm;
    vi small(hp);
    AhoCorasick ac;
    RP(x, hp) {
        string temp;
        cin >> temp;
        vi aa(wp);
        RP(y, wp) {
            aa[y] = to_index(temp[y]);
        }
        // 작은 그림의 sequence를 만들어낸다.
        small[x] = ac.add(ac.root, aa, 0);
    }

    ac.createFail();
    vvi board = vvi(hm);

    RP(x, hm) {
        string temp;
        cin >> temp;
        vi aa(wm);
        RP(y, wm) {
            aa[y] = to_index(temp[y]);
        }
        board[x] = ac.search(aa);
    }

    // small의 fail 을 구하고.
    vi fail(hp, 0);
    for (int i = 1, j = 0; i < hm; i++) {
        while (j > 0 && small[i] != small[j]) j = fail[j - 1];
        if (small[i] == small[j]) fail[i] = ++j;
    }

    int cnt = 0;
    RP(y, wm) { // 전체는 O(wm * (hm + hp)) => O(N^2)
        // kmp 를 돌려서 갯수 기록 KMP 자체는 O(hm + hp)이고.
        for (int i = 0, j = 0; i < hm; i++) {
            while (j > 0 && board[i][y] != small[j]) j = fail[j - 1];
            if (board[i][y] == small[j]) {
                if (j == hp - 1) {
                    cnt++;
                    j = fail[j];
                } else {
                    j++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
