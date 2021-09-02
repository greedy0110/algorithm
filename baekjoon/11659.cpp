//
// Created by 신승민 on 2021/09/02.
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

    int N, M;
    cin >> N >> M;
    vi psum(N + 1);
    psum[0] = 0;
    RP(i, N) {
        int a;
        cin >> a;
        psum[i + 1] = psum[i] + a;
    }
    RP(_, M) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << psum[j + 1] - psum[i] << endl;
    }

    return 0;
}
