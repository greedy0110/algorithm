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

public:
    vector<Node> trie;
    int root;

    int init() {
        // trie 마지막에 노드를 설치하고 인덱스 반환.
        Node x;
        trie.push_back(x);
        return (int) trie.size() - 1;
    }

    Trie() {
        root = init();
    }

    void add(int node, const string &s, int index) {
        if (index == s.size()) {
            trie[node].valid = true;
            return;
        }
        int c = s[index] - 'a';
        int &child = trie[node].children[c];
        if (child == -1) { // 해당 자식이 없으면, 새로 만들어야 한다.
            int n = init();
            child = n;
        }
        add(child, s, index + 1);
    }

    bool search(int node, const string &s, int index) {
        if (node == -1) return false;
        assert(trie.size() > node);
//        if (s.size() == index) return trie[node].valid;
        if (s.size() == index) return true;

        int c = s[index] - 'a';
        int child = trie[node].children[c];
        return search(child, s, index + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Trie trie;
    int N, M;
    cin >> N >> M;
    vector<string> S(N);

    RP(i, N) {
        string temp;
        cin >> temp;
        trie.add(trie.root, temp, 0);
    }

    int cnt = 0;
    RP(i, M) {
        string temp;
        cin >> temp;
        if (trie.search(trie.root, temp, 0)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}
