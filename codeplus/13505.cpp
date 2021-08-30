//
// Created by 신승민 on 2021/08/30.
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

const int MAX_SIZE = 32;

class Trie {
    struct Node {
        int children[2];
        int cnt;

        Node() {
            children[0] = -1;
            children[1] = -1;
            cnt = 0;
        };
    };

    vector<Node> trie;
public:
    int root;

    int createNode() {
        Node x;
        trie.push_back(x);
        return (int) trie.size() - 1;
    }

    Trie() {
        root = createNode();
    }

    void add(int node, int target, int bit) {
        if (bit == -1) {
            trie[node].cnt++;
            return;
        }

        int c = (target >> bit) & 1;
        int &child = trie[node].children[c];
        if (child == -1) {
            child = createNode();
        }
        add(child, target, bit - 1);
    }

    int query(int node, int target, int bit) {
        if (node == -1) return 0;
        Node &cur = trie[node];
        if (bit == -1) {
            // 찾음. 가산할 때 아무런 영향이 없어야함. 0 반환함.
            return 0;
        }

        int c = (target >> bit) & 1;
        c = 1 - c;
        if (cur.children[c] == -1) {
            c = 1 - c;
        }

        if (cur.children[c] == -1) {
            return 0;
        }

        int next = 0;
        if (c == 1) next = 1 << bit;
        return next | query(cur.children[c], target, bit - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vi A(N);
    Trie trie;
    RP(i, N) {
        cin >> A[i];
        trie.add(trie.root, A[i], 31);
    }

    int ans = -1;
    RP(i, N) {
        int aj = trie.query(trie.root, A[i], 31);
        ans = max(ans, A[i] ^ aj);
    }
    cout << ans << endl;

    return 0;
}
