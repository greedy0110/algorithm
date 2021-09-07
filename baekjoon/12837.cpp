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
    int day_to_node(int node, int s, int e, int index) {
        if (s == e && s == index) return node;
        if (s <= index && index <= e) {
            int mid = (s + e) / 2;
            int left = day_to_node(node * 2, s, mid, index);
            int right = day_to_node(node * 2 + 1, mid + 1, e, index);
            if (left != -1) return left;
            if (right != -1) return right;
        }
        return -1;
    }

    ll sum(int node, int s, int e, int fs, int fe) {
        if (fe < s || e < fs) return 0;
        if (fs <= s && e <= fe) return tree[node];
        int mid = (s + e) / 2, left = node * 2, right = node * 2 + 1;
        return sum(left, s, mid, fs, fe) + sum(right, mid + 1, e, fs, fe);
    }

    int N, root;
    vector<ll> elements;
    vector<ll> tree;
public:
    SegmentTree(int n) : N(n) {
        elements = vector<ll>(n, 0);
        tree = vector<ll>(4 * n, 0); // 초기 값 필요없음.
        root = 1;
    }

    // 이 문제에선, 입력 자체가 diff를 의미한다. (수입, 지출이잖아?)
    void update(int day, int diff) {
        int node = day_to_node(root, 0, N - 1, day - 1);
        elements[day - 1] += diff;
        tree[node] += diff;

        while (node != 0) {
            node /= 2;
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll sum(int s, int e) {
        return sum(root, 0, N - 1, s - 1, e - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    SegmentTree st(N);
    RP(_, Q) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            st.update(b, c);
        } else {
            cout << st.sum(b, c) << endl;
        }
    }

    return 0;
}
