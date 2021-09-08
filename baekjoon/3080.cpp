//
// Created by 신승민 on 2021/09/07.
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
    static const ll MOD = 1000000007;

    struct Node {
        vector<pair<char, int>> children;
        bool value;

        Node() {
            value = false;
        }

        int getChild(char c) {
            for (auto &child: children) {
                if (child.first == c) return child.second;
            }
            return -1;
        }
    };

    vector<Node> trie;
    int root;

    int initNode() {
        Node x;
        trie.push_back(x);
        trie.shrink_to_fit();
        return (int) trie.size() - 1;
    }

    int num_children(int node) {
        return trie[node].children.size();
    }

    ll facto(int n) {
        ll ret = 1;
        for (ll i = 1; i <= n; i++) {
            ret *= i;
            ret %= MOD;
        }
        return ret;
    }

    void insert(int node, const string &p, int index) {
        if (p.size() == index) {
            trie[node].value = true;
            return;
        }

        int child = trie[node].getChild(p[index]);
        if (child == -1) {
            child = initNode();
            trie[node].children.push_back({p[index], child});
            trie[node].children.shrink_to_fit();
        }
        insert(child, p, index + 1);
    }

    ll sub(int node) {
        // 자식의 갯수를 샌다. 이것을 팩토리얼 한 것을 곱한다.
        // 자식이 없다면, 1을 반환한다.
        // 자식의 sub(child) 한 것을 모두 곱한다.
        // 반환한다.
        int num_c = num_children(node);
        if (num_c == 0) return 1;
        ll ret = facto(num_c);
        for (auto &child: trie[node].children) {
            ret *= sub(child.second);
            ret %= MOD;
        }

        if (trie[node].value) {
            ret *= 2; // 본인이 valid 라면, 자식 노드가 만드는 리스트 위나 아래에 들어갈 수 있음.
            ret %= MOD;
        }

        return ret;
    }

public:
    Trie() {
        root = initNode();
    }

    void insert(const string &p) {
        insert(root, p, 0);
    }

    ll solve() {
        return sub(root);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    Trie trie;
    RP(_, N) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    cout << trie.solve() << endl;

    return 0;
}
