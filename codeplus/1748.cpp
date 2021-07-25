//
// Created by 신승민 on 2021/07/25.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N;
    cin >> N;
    long long ans = 0;
    for (long long start = 1, len = 1; start <= N; start *= 10, len += 1) {
        long long end = start * 10 - 1;
        if (end > N) {
            end = N;
        }
        ans += len * (end - start + 1);
    }
    cout << ans << endl;

    return 0;
}
