//
// Created by 신승민 on 2021/08/02.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

struct J {
    int m, v, w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<J> js;
    RP(_, N) {
        int m, v;
        cin >> m >> v;
        js.push_back({m, v, 0});
    }
    RP(_, K) {
        int m;
        cin >> m;
        js.push_back({m, -1, 1});
    }

    sort(all(js), [&](const J &a, const J &b) {
        return a.m < b.m || ((a.m == b.m) && a.w < b.w);
    });

    priority_queue<ll> pq;
    ll ans = 0;
    for (auto &j : js) {
        if (j.w == 1) {
            if (pq.empty()) continue;
            ans += pq.top();
            pq.pop();
        } else {
            pq.push(j.v);
        }
    }

    cout << ans << endl;

    return 0;
}
