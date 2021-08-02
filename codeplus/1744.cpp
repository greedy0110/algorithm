//
// Created by 신승민 on 2021/08/02.
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

    int N;
    cin >> N;
    vi M, P;
    bool zero = false;
    int one = 0;
    RP(_, N) {
        int num;
        cin >> num;
        if (num >= 2) P.push_back(num);
        else if (num <= -1) M.push_back(num);
        else if (num == 0) zero = true;
        else if (num == 1) one++;
    }

    sort(all(P), [](int a, int b) { return a > b; });
    sort(all(M));

    int ans = one; // 1은 있으면 무조건 더함.

    if (P.size() % 2 == 1) {
        P.push_back(1);
    }
    for (int i = 0; i < P.size(); i += 2) {
        ans += P[i] * P[i + 1];
    }

    if (M.size() % 2 == 1) {
        if (zero) {
            M.push_back(0);
        } else {
            M.push_back(1);
        }
    }

    for (int i = 0; i < M.size(); i += 2) {
        ans += M[i] * M[i + 1];
    }

    cout << ans << endl;

    return 0;
}
