//
// Created by 신승민 on 2021/09/19.
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

int d, n, k;
vi cs;
vector<pair<int, int>> pos;

vi go(int day) {
    vi ret;
    for (int i = 0; i < n; i++) {
        auto p = pos[i];
        if (p.first <= day && day <= p.second) {
            ret.push_back(cs[i]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> d >> n >> k;
        pos.clear();
        cs.clear();

        RP(_, n) {
            int s, e, c;
            cin >> c >> s >> e;
            pos.push_back({s, e});
            cs.push_back(c);
        }

        ll ans = 0;
        for (int day = 1; day <= d; day++) {
            auto sub = go(day);
            sort(all(sub));
            ll temp = 0;
            for (int i = 0; i < min(k, (int) sub.size()); i++) {
                temp += sub[(int) sub.size() - 1 - i];
            }
            ans = max(ans, temp);
        }

        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }

    return 0;
}
