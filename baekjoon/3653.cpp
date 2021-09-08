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
    int N, M;
    int root = 1;
    vi tree;
    vi elements;
    map<int, int> indices;

    int init(int node, int s, int e) {
        if (s == e) return tree[node] = elements[s];
        int mid = (s + e) / 2, left = node * 2, right = node * 2 + 1;
        return tree[node] = init(left, s, mid) + init(right, mid + 1, e);
    }

    int sum(int node, int s, int e, int fs, int fe) {
        if (fe < s || e < fs) return 0;
        if (fs <= s && e <= fe) return tree[node];
        int mid = (s + e) / 2, left = node * 2, right = node * 2 + 1;
        return sum(left, s, mid, fs, fe) + sum(right, mid + 1, e, fs, fe);
    }

    int index_to_node(int node, int s, int e, int index) {
        if (s == e && s == index) return node;
        if (s <= index && index <= e) {
            int mid = (s + e) / 2, left = node * 2, right = node * 2 + 1;
            left = index_to_node(left, s, mid, index);
            right = index_to_node(right, mid + 1, e, index);
            if (left != -1) return left;
            if (right != -1) return right;
        }
        return -1;
    }

    void update(int index, int diff) {
        int node = index_to_node(root, 0, N + M - 1, index);
        tree[node] += diff;
        while (node != root) {
            node /= 2;
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

public:
    SegmentTree(int N, int M) : N(N), M(M) {
        tree = vi(4 * (N + M));
        elements = vi(N + M, 0);
        for (int i = 0; i < N; i++) {
            elements[i] = 1;
            indices[N - i] = i;
        }
        init(root, 0, N + M - 1);
    }

    int solve(int movie, int i) {
        int cur = indices[movie]; // movie 의 현재 위치는?
        int ans = sum(root, 0, N + M - 1, cur + 1, N + M - 1);

        elements[cur] = 0; // 지금 영화를 N+i 위치로 옮기자.
        elements[N + i] = 1;
        indices[movie] = N + i;

        update(cur, -1);
        update(N + i, 1);

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        SegmentTree st(N, M);
        RP(i, M) {
            int movie;
            cin >> movie;
            cout << st.solve(movie, i) << " ";
        }
        cout << endl;
    }

    return 0;
}
