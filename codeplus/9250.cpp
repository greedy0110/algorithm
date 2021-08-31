//
// Created by 신승민 on 2021/08/31.
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

        Node() {
            children = vi(26, -1);
            valid = false;
        }
    };

    vector<Node> trie;
    vi fail;
    int root;

    int createNode() {
        Node x;
        trie.push_back(x);
        return (int) trie.size() - 1;
    }

    // pattern 들로 trie를 구성하자.
    void add(int node, const string &p, int index) {
        if (index == p.size()) {
            trie[node].valid = true;
            return;
        }

        int c = p[index] - 'a';
        int &child = trie[node].children[c];
        if (child == -1) child = createNode();
        add(child, p, index + 1);
    }

public:
    AhoCorasick() {
        root = createNode();
    }

    void add(const string &s) {
        add(root, s, 0);
    }

    void createFail() {
        fail = vi(trie.size(), -1);

        // 레벨 별 순회해야 하므로, BFS 개념을 이용한다.
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                int next = trie[cur].children[i];
                if (next == -1) continue;
                if (cur == root) fail[next] = root;
                else {
                    int x = fail[cur];
                    while (x != root && trie[x].children[i] == -1) { // fail 함수로 이동한 곳에 children 이 없다면, 다시 이동하자.
                        x = fail[x];
                    }
                    if (trie[x].children[i] != -1) { // 결국 찾았다면.
                        x = trie[x].children[i];
                    }
                    fail[next] = x;
                }
                // next의 전 것이 valid 했다면, (포함여부를 나타내는 관점에서 역시 valid하다.)
                trie[next].valid |= trie[fail[next]].valid;
                q.push(next);
            }
        }
    }

    // 해당 문자열에 드러맞는 패턴이 있는지 검사한다.
    bool pattern(const string &s) {
        int n = s.size();
        int node = root;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            while (node != root && trie[node].children[c] == -1) {
                node = fail[node];
            }
            if (trie[node].children[c] != -1) {
                node = trie[node].children[c];
            }
            if (trie[node].valid) ok = true;
        }
        return ok;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N;
    AhoCorasick ac;
    while (N--) {
        string temp;
        cin >> temp;
        ac.add(temp);
    }
    ac.createFail();
    cin >> Q;
    while (Q--) {
        string temp;
        cin >> temp;
        cout << (ac.pattern(temp) ? "YES" : "NO") << endl;
    }

    return 0;
}
