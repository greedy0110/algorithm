//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

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
    vi radix(10001, 0);
    RP(_, N) {
        int a;
        cin >> a;
        radix[a]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < radix[i]; j++) {
            cout << i << endl;
        }
    }

    return 0;
}
