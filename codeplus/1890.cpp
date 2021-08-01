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
typedef long long ll;

int N;
int A[100][100];
ll cache[100][100] = {};

ll go(int x, int y) {
    if (x == N - 1 && y == N - 1) return 1;
    if (x < 0 || N <= x || y < 0 || N <= y) return 0;

    ll &cac = cache[x][y];
    if (cac != 0) return cac;

    int step = A[x][y];
    if (step == 0) return 0;
    return cac = go(x + step, y) + go(x, y + step);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    RP(i, N) RP(j, N) cin >> A[i][j];

    cout << go(0, 0) << endl;

    return 0;
}
