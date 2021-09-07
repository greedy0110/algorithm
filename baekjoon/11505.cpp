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

class SegmentTree {
    static const int MOD = 1000000007;

    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = elements[s];
        int mid = (s + e) / 2;
        tree[node] = init(node * 2, s, mid) * init(node * 2 + 1, mid + 1, e);
        tree[node] %= MOD;
        return tree[node];
    }

    ll calc(int node, int s, int e, int find_s, int find_e) {
        // 구간이랑 상관 없을 때.
        if (find_e < s || e < find_s) return 1;

        // 구간에 완전히 포함될 때.
        if (find_s <= s && e <= find_e) return tree[node];

        // 일부 걸쳤을 때.
        int mid = (s + e) / 2;
        return (calc(node * 2, s, mid, find_s, find_e) * calc(node * 2 + 1, mid + 1, e, find_s, find_e)) % MOD;
    }

    int index_to_node(int node, int s, int e, int index) {
        if (s == e && s == index) return node;
        if (s <= index && index <= e) {
            int mid = (s + e) / 2;
            int left = index_to_node(node * 2, s, mid, index);
            int right = index_to_node(node * 2 + 1, mid + 1, e, index);
            if (left != -1) return left;
            if (right != -1) return right;
        }
        return -1;
    }

    vector<ll> elements;
    int root = 1; // 편의를 위해서 root 는 1부터 시작한다.
public:
    vector<ll> tree;

    SegmentTree(const vector<ll> &elements) : elements(elements) {
        int n = elements.size();
        tree = vector<ll>(4 * n); // 크기를 대충 넉넉하게 잡아도 좋다.
        init(1, 0, n - 1);
    }

    ll sum(int s, int e) {
        return calc(root, 0, (int) elements.size() - 1, s, e);
    }

    void update(int index, ll value) {
        int node = index_to_node(root, 0, (int) elements.size() - 1, index);
        elements[index] = value;
        tree[node] = value;

        // 노드 부터 갱신하자.
        while (node != 0) {
            node /= 2;
            tree[node] = tree[node * 2] * tree[node * 2 + 1];
            tree[node] %= MOD;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    RP(i, N) cin >> A[i];
    SegmentTree st(A);
    RP(_, M + K) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            st.update((int) b - 1, c);
        } else {
            cout << st.sum((int) b - 1, (int) c - 1) << endl;
        }
    }

    return 0;
}
