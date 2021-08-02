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

struct jewelry {
    int m, v;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<jewelry> js(N);
    RP(i, N) {
        int m, v;
        cin >> m >> v;
        js[i] = {m, v};
    }
    multiset<int> bags;
    RP(j, K) {
        int c;
        cin >> c;
        bags.insert(c);
    }

    sort(all(js), [&](const jewelry &a, const jewelry &b) {
        return a.v > b.v;
    });

    ll ans = 0;
    RP(i, N) {
        int v = js[i].v;
        int m = js[i].m;

        auto it = bags.lower_bound(m);
        if (it == bags.end()) continue;
        bags.erase(it);
        ans += (ll)v;
    }
    cout << ans << endl;

    return 0;
}
