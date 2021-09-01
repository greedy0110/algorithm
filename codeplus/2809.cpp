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
        map<char, int> children;
        bool valid;
        int size;

        Node() {
            valid = false;
            size = 0;
        }

    public:
        bool hasChild(char c) {
            return children.count(c) != 0;
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

    void add(int node, const string &p, int index) {
        if (p.size() == index) {
            trie[node].valid = true;
            trie[node].size = p.size();
            return;
        }

        if (!trie[node].hasChild(p[index])) {
            trie[node].children[p[index]] = createNode();
        }
        add(trie[node].children[p[index]], p, index + 1);
    }

public:
    AhoCorasick() {
        root = createNode();
    }

    void add(const string &p) {
        add(root, p, 0);
    }

    void createFail() {
        fail = vi(trie.size());
        fail[root] = root;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &keyvalue : trie[cur].children) {
                char key = keyvalue.first;
                int next = keyvalue.second;
                if (cur == root) fail[next] = root;
                else {
                    // cur 의 suffix 들을 큰것 부터 작은 순으로
                    // 하나씩 순회하면서, 다음 요소로 i를 가지고 있는 친구를 찾는다.
                    // 그리고 i가 있다면? x에 해당 i가 위치한 노드를 향하도록한다.
                    // 그렇지 않다면? 어차피 root일 것이다.
                    int x = fail[cur];
                    while (x != root && !trie[x].hasChild(key)) x = fail[x];
                    if (trie[x].hasChild(key)) x = trie[x].children[key];
                    fail[next] = x;
                }

                // suffix 의 사이즈 만큼. 볼수 있다.
                trie[next].valid |= trie[fail[next]].valid;
                // * 노드에 부가 정보를 붙혀서 원하는 바를 얻을 수 있는가?
                trie[next].size = max(trie[next].size, trie[fail[next]].size);
                q.push(next);
            }
        }
    }

    int num_covered(const string &s) {
        vi covered(s.size(), 0);
        int node = root;
        for (int i = 0; i < s.size(); i++) {
            while (node != root && !trie[node].hasChild(s[i])) node = fail[node];
            if (trie[node].hasChild(s[i])) node = trie[node].children[s[i]];

            if (trie[node].valid) {
                // i 인덱스로부터 size 만큼 뒤로 패턴이 존재했다는 것.
                int start = i - trie[node].size + 1;
                assert(start >= 0);
                for (int j = start; j <= i; j++) covered[j] = 1;
            }
        }
        int sum = 0;
        for (int c : covered) sum += c;
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    string s;
    cin >> N >> s;
    AhoCorasick ac;
    cin >> M;
    RP(_, M) {
        string temp;
        cin >> temp;
        ac.add(temp);
    }
    ac.createFail();

    cout << N - ac.num_covered(s) << endl;

    return 0;
}
