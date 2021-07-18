//
// Created by 신승민 on 2021/07/18.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef pair<long long, long long> pii;

pii count25(long long n) {
    long long five = 0, two = 0;
    for (long long i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    for (long long i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    return make_pair(two, five);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    pii c = count25(N);
    pii m1 = count25(N - M);
    pii m2 = count25(M);

    cout << min(c.first - m1.first - m2.first, c.second - m1.second - m2.second) << endl;

    return 0;
}
