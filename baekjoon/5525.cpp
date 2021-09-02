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

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    char pv = S[0];
    bool foundI = pv == 'I';
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i < S.size(); i++) {
        char cur = S[i];
        if (!foundI) {
            if (cur == 'I') foundI = true;
            pv = cur;
            continue;
        } else {
            if (pv == 'I' && cur == 'I') {
                if (cnt >= N) ans += (cnt - N + 1);
                cnt = 0;
            } else if (pv == 'I' && cur == 'O') {
                cnt++;
            } else if (pv == 'O' && cur == 'O') {
                if (cnt - 1 >= N) ans += (cnt - N);
                cnt = 0;
            } else {
                if (i == S.size() - 1) {
                    if (cnt >= N) ans += (cnt - N + 1);
                }
            }
            pv = cur;
        }
    }
    cout << ans << endl;

    return 0;
}
