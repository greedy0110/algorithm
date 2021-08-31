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
        int cnt;

        Node() {
            children = vi(4, -1);
            cnt = 0;
        }
    };

    int root;
    vector<Node> trie;
    vi fail;

    int createNode() {
        Node x;
        trie.push_back(x);
        return (int) trie.size() - 1;
    }

    void add(int node, const vi &p, int index) {
        if (p.size() == index) {
            // 중복된 패턴이 들어와도, 초기 만들 때에는 1개 씩만 카운트하자.
            trie[node].cnt = 1;
            return;
        }

        int c = p[index];
        int &child = trie[node].children[c];
        if (child == -1) child = createNode();
        add(child, p, index + 1);
    }

public:
    AhoCorasick() {
        root = createNode();
    }

    void add(const vi &p) {
        add(root, p, 0);
    }

    void createFail() {
        fail = vi(trie.size(), -1);
        queue<int> q;
        fail[root] = root;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next = trie[cur].children[i];
                if (next == -1) continue;
                if (cur == root) fail[next] = root;
                else {
                    int x = fail[cur];
                    while (x != root && trie[x].children[i] == -1) x = fail[x];
                    if (trie[x].children[i] != -1) x = trie[x].children[i];
                    fail[next] = x;
                }
                trie[next].cnt += trie[fail[next]].cnt;
                q.push(next);
            }
        }
    }

    int find_from(const vi &s) {
        int node = root;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i];
            while (node != root && trie[node].children[c] == -1) node = fail[node];
            if (trie[node].children[c] != -1) { // s[i]로 인해서 이동할 수 있다.
                node = trie[node].children[c]; // 그냥 다음으로 이동한다.
            }
            cnt += trie[node].cnt; // 이동할 때, 발견한 모든 걸 더한다.
        }
        return cnt;
    }
};

int transform(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vi dna(N), marker(M);
        string d, m;
        cin >> d >> m;
        RP(i, N) dna[i] = transform(d[i]);
        RP(i, M) marker[i] = transform(m[i]);

        AhoCorasick ac;
        ac.add(marker);
        for (int i = 0; i < M - 1; i++) {
            for (int j = i + 1; j < M; j++) {
                reverse(marker.begin() + i, marker.begin() + j + 1);
                ac.add(marker);
                reverse(marker.begin() + i, marker.begin() + j + 1);
            }
        }

        ac.createFail();

        cout << ac.find_from(dna) << endl;
    }

    return 0;
}
