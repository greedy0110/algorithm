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
    void init(int node, int s, int e) {
        if (s == e) {
            tree_max[node] = elements[s];
            tree_min[node] = elements[s];
            return;
        }
        int mid = (s + e) / 2;
        int left = node * 2, right = left + 1;

        init(left, s, mid);
        init(right, mid + 1, e);
        tree_max[node] = max(tree_max[left], tree_max[right]);
        tree_min[node] = min(tree_min[left], tree_min[right]);
    }

    // 최대, 최소 반환.
    pair<int, int> calc(int node, int s, int e, int find_s, int find_e) {
        // 구간이랑 상관 없을 때.
        if (find_e < s || e < find_s) return {0, 1000000000}; // 문제 조건상 의미 없는 숫자.
        // 구간에 완전히 포함될 때.
        if (find_s <= s && e <= find_e) return {tree_max[node], tree_min[node]};

        // 일부 걸쳤을 때.
        int mid = (s + e) / 2;
        auto left = calc(node * 2, s, mid, find_s, find_e);
        auto right = calc(node * 2 + 1, mid + 1, e, find_s, find_e);
        return {max(left.first, right.first), min(left.second, right.second)};
    }

    vector<ll> elements;
    int root = 1; // 편의를 위해서 root 는 1부터 시작한다.
public:
    vector<ll> tree_max;
    vector<ll> tree_min;

    SegmentTree(const vector<ll> &elements) : elements(elements) {
        int n = elements.size();
        tree_min = vector<ll>(4 * n); // 크기를 대충 넉넉하게 잡아도 좋다.
        tree_max = vector<ll>(4 * n); // 크기를 대충 넉넉하게 잡아도 좋다.
        init(1, 0, n - 1);
    }

    pair<int, int> sum(int s, int e) {
        return calc(root, 0, (int) elements.size() - 1, s, e);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    RP(i, N) cin >> A[i];
    SegmentTree st(A);
    RP(_, M) {
        int a, b;
        cin >> a >> b;
        auto ret = st.sum(a - 1, b - 1);
        cout << ret.second << " " << ret.first << endl;
    }

    return 0;
}
