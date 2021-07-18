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

    int five = 0, N;
    cin >> N;
    for (int i = 5; i <= N; i *= 5) {
        five += N / i;
    }
    cout << five << endl;

    return 0;
}
