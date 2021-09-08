//
// Created by 신승민 on 2021/09/08.
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
    int N;
    int root = 1;
    vector<ll> tree;
    vector<ll> elements;

    ll sum(int node, int s, int e, int fs, int fe) {
        if (fe < s || e < fs) return 0;
        if (fs <= s && e <= fe) return tree[node];
        int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;
        return sum(left, s, mid, fs, fe) + sum(right, mid + 1, e, fs, fe);
    }

    int index_to_node(int node, int index, int s, int e) {
        if (s == e && s == index) return node;
        if (s <= index && index <= e) {
            int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;
            left = index_to_node(left, index, s, mid);
            right = index_to_node(right, index, mid + 1, e);
            if (left != -1) return left;
            if (right != -1) return right;
        }
        return -1;
    }

    void update(int index, ll diff) {
        int node = index_to_node(root, index, 0, N - 1);
        tree[node] += diff;
        while (node != 1) {
            node /= 2;
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

public:
    SegmentTree(int N) : N(N) {
        tree = vector<ll>(4 * N, 0);
        elements = vector<ll>(N, 0);
    }

    ll sum(int i, int j) {
        return sum(root, 0, N - 1, i, j);
    }

    void update(int index, int value) {
        ll diff = value - elements[index];
        elements[index] = value;
        update(index, diff);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    SegmentTree st(N);
    RP(_, M) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            b--;
            c--;
            if (b > c) swap(b, c);

            cout << st.sum(b, c) << endl;
        } else {
            b--;
            st.update(b, c);
        }
    }

    return 0;
}
