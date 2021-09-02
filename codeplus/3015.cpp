//
// Created by 신승민 on 2021/09/01.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> s;
    int N;
    cin >> N;
    ll ans = 0;
    RP(_, N) {
        int now;
        cin >> now;
        if (s.empty()) {
            s.push_back(now);
        } else {
            while (!s.empty() && s.back() < now) {
                s.pop_back();
                ans += 1LL;
            }

            for (int i = (int) s.size() - 1; i >= 0; i--) {
                if (s[i] == now) ans += 1LL;
                if (s[i] > now) {
                    ans += 1LL;
                    break;
                }
            }
            s.push_back(now);
        }
    }

    cout << ans << endl;

    return 0;
}
