//
// Created by 신승민 on 2021/06/20.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define SUPER_BIG numeric_limits<double>::max()

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

class UnionFind {
private:
    vi ps;
public:
    UnionFind(int n) {
        ps = vi(n);
        for (int i = 0; i < n; i++) ps[i] = i;
    }

    int find(int u) {
        if (u == ps[u]) return u;
        return ps[u] = find(ps[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        ps[u] = v;
    }
};

void solve() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vi deck(M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &deck[i]);
    }

    sort(all(deck));
    UnionFind uf(N + 1);

    for (int i = 0; i < K; i++) {
        int card;
        scanf("%d", &card);

        int start = 0, end = M - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            int cm = uf.find(deck[mid]);

            if (card >= cm) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        printf("%d\n", uf.find(deck[end]));
        uf.merge(deck[end], end == 0 ? 0 : deck[end - 1]);
    }
}
