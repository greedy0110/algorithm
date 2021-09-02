//
// Created by 신승민 on 2021/09/02.
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

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<string, int> cnt;
        while (N--) {
            string temp;
            cin >> temp >> temp;
            auto it = cnt.find(temp);
            cnt[temp]++;
        }
        int ans = 1;
        for (auto &p : cnt) {
            ans *= (p.second + 1);
        }
        cout << ans - 1 << endl;
    }

    return 0;
}
