//
// Created by 신승민 on 2021/08/07.
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

    int N, M, K;
    cin >> N >> M >> K;
    vi ans(N);
    if (M + K - 1 <= N && N <= M * K) {
        RP(i, N) ans[i] = i + 1;

        vi g;
        g.push_back(0);
        g.push_back(K); // [0, K)

        N -= K;
        M -= 1;

        int gs = M == 0 ? 1 : N / M;
        int r = M == 0 ? 0 : N % M;
        while (M != 0) {
            int size = gs + (r > 0 ? 1 : 0);
            g.push_back(g.back() + size);
            if (r > 0) r--;
            M -= 1;
        }

        for (int i = 0; i < (int) g.size() - 1; i++) {
            reverse(ans.begin() + g[i], ans.begin() + g[i + 1]);
        }
        for (int a: ans) {
            cout << a << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
