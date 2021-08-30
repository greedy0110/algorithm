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

class Trie {
    static const int C_SIZE = 26;

    struct Node {
        vi children;
        bool valid;

        Node() {
            children = vi(C_SIZE, -1);
            valid = false;
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

    void add(int node, const string &s, int index) {
        if (index == s.size()) {
            trie[node].valid = true;
            return;
        }

        int c = s[index] - 'a';
        int &child = trie[node].children[c];
        if (child == -1) {
            child = createNode();
        }
        assert(child != -1);
        add(child, s, index + 1);
    }

    void count(int node, const string &s, int index, int &ans) {
        if (node == -1) return;
        if (index == s.size()) return;

        int c = s[index] - 'a';
        int child = trie[node].children[c];
        int num = num_children(node);
        assert(num != 0);
        assert(child != -1); // 항상, 트라이를 만든 문자열을 집어넣을 것이라. 자식이 없는 경로는 없다.

        if (node == root || trie[node].valid || num > 1) {
            ans++;
            count(child, s, index + 1, ans);
        } else {
            count(child, s, index + 1, ans);
        }
    }

    int num_children(int node) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (trie[node].children[i] != -1) ans++;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (cin.eof()) return 0;
        vector<string> words(N);
        Trie trie;
        RP(i, N) {
            cin >> words[i];
            trie.add(trie.root, words[i], 0);
        }

        int sum = 0;
        RP(i, N) {
            int temp = 0;
            trie.count(trie.root, words[i], 0, temp);
            sum += temp;
        }

        cout << setprecision(2) << fixed << (float) sum / (float) N << endl;
    }

    return 0;
}
