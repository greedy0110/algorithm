//
// Created by 신승민 on 2021/09/01.
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

    vi fb(46);
    fb[0] = 0;
    fb[1] = 1;
    for (int i = 2; i < 46; i++) fb[i] = fb[i - 1] + fb[i - 2];
    int N;
    cin >> N;
    cout << fb[N] << endl;

    return 0;
}
