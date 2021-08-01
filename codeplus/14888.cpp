//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int N;
vi A;
vi ops;

int calc() {
    int acc = A[0];
    for (int i = 0; i < N - 1; i++) {
        int t = A[i + 1];
        switch (ops[i]) {
            case 0:
                acc += t;
                break;
            case 1:
                acc -= t;
                break;
            case 2:
                acc *= t;
                break;
            case 3:
                acc /= t;
                break;
        }
    }
    return acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vi(N);
    RP(i, N) cin >> A[i];
    RP(i, 4) {
        int cnt;
        cin >> cnt;
        RP(_, cnt) ops.push_back(i);
    }
    assert(ops.size() == N-1);

    int ans_max = -1000000000;
    int ans_min = 1000000000;
    do {
        int temp = calc();

        ans_max = max(ans_max, temp);
        ans_min = min(ans_min, temp);
    } while (next_permutation(all(ops)));

    cout << ans_max << endl << ans_min << endl;

    return 0;
}
