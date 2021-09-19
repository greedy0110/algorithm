//
// Created by 신승민 on 2021/09/20.
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

class Trie {
public:
    struct Node {
        map<char, int> children;
        vector<char> order;

        bool hasChild(char c) {
            return children.find(c) != children.end();
        }

        void addChild(char c, int index) {
            children[c] = index;
            order.push_back(c);
        }

        int getChild(char c) {
            return children[c];
        }
    };

    int root;
    vector<Node> trie;

    int next() {
        trie.emplace_back();
        return (int) trie.size() - 1;
    }

    Trie() {
        root = next();
    }

    void add(int node, const string &s, int index) {
        if (s.size() == index) {
            return;
        }

        char c = s[index];
        if (!trie[node].hasChild(c)) {
            int n = next();
            trie[node].addChild(c, n);
            add(n, s, index + 1);
        } else {
            add(trie[node].getChild(c), s, index + 1);
        }
    }

    void make_g(int node, vvi &g) {
        auto &cur = trie[node];

        for (int i = 0; i < (int) cur.order.size() - 1; i++) {
            int u = cur.order[i] - 'a';
            int v = cur.order[i + 1] - 'a';
            g[u][v] = 1;
        }

        for (auto &p : cur.children) {
            make_g(p.second, g);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int NUM = 26;

    int n;
    cin >> n;

    vvi g(NUM, vi(NUM, 0));
    vi ind(NUM, 0);
    vb filter(NUM, false);

    Trie trie;
    string prev;
    bool ok = true;
    RP(_, n) {
        string word;
        cin >> word;

        for (char c : word) filter[c - 'a'] = true;
        trie.add(trie.root, word, 0);

        if (prev.size() > word.size()) {
            if (prev.substr(0, word.size()) == word) {
                ok = false;
            }
        }
        prev = word;
    }
    if (!ok) {
        cout << "!" << endl;
        return 0;
    }

    trie.make_g(trie.root, g);

    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            if (i == j) continue;
            if (g[i][j] == 1) ind[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < NUM; i++) {
        if (ind[i] == 0 && filter[i]) q.push(i);
    }

    int vs = 0;
    for (bool f : filter) if (f) vs++;

    vi order;
    bool multipath = false;
    for (int i = 0; i < vs; i++) {
        if (q.empty()) {
            cout << "!" << endl;
            return 0;
        }
        if (q.size() >= 2) {
            multipath = true;
        }

        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v = 0; v < NUM; v++) {
            if (g[u][v] == 1) {
                ind[v]--;
                if (ind[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    if (multipath) {
        cout << "?" << endl;
        return 0;
    }

    for (int a : order) {
        cout << (char) (a + 'a');
    }
    cout << endl;

    return 0;
}
