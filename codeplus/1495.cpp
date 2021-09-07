//
// Created by 신승민 on 2021/09/05.
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

vi V;
int N, S, M;
vvi cache;

int go(int index, int volume) {
    if (volume < 0 || volume > M) return -1;
    if (index == N) {
        return volume;
    }

    int &cac = cache[index][volume];
    if (cac != -2) return cac;

    cac = max(cac, go(index + 1, volume + V[index]));
    cac = max(cac, go(index + 1, volume - V[index]));

    return cac;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S >> M;
    V = vi(N);
    cache = vvi(N, vi(M + 1, -2));
    RP(i, N) cin >> V[i];

    cout << go(0, S) << endl;

    return 0;
}
