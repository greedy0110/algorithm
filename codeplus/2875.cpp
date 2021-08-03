//
// Created by 신승민 on 2021/08/03.
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
    while (K--) {
        if (N == 0 || M == 0) {
            cout << 0 << endl;
            return 0;
        }

        if (N > 2 * M) N--;
        else M--;
    }

    cout << min(N / 2, M) << endl;

    return 0;
}
