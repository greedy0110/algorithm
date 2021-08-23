//
// Created by 신승민 on 2021/08/23.
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

    int N, L, R, X;
    cin >> N >> L >> R >> X;
    vi A(N);
    RP(i, N) cin >> A[i];

    int cnt = 0;
    for (int i = 0; i < (1 << N); i++) {
        vi indices;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) indices.push_back(j);
        }
        if (indices.size() < 2) continue;

        int sum = 0;
        int diff = 0, easy = 1e7;
        for (int index: indices) {
            int hard = A[index];

            diff = max(diff, hard);
            easy = min(easy, hard);
            sum += hard;
        }

        if (sum < L || sum > R) continue;
        if (diff - easy < X) continue;

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
