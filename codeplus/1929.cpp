//
// Created by 신승민 on 2021/07/18.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;
    vector<bool> prime(N + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            prime[j] = false;
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime[i]) cout << i << endl;
    }

    return 0;
}
