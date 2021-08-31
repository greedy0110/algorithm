//
// Created by 신승민 on 2021/08/31.
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

int N;
vi T;
vi P;
vi cache;

int go(int day) {
    if (day == N + 1) return 0;
    int &cac = cache[day];
    if (cac != -1) return cac;

    // day 를 안할 때
    int ans = go(day + 1);
    // day 를 할 때
    if (day + T[day] <= N + 1) {
        ans = max(ans, go(day + T[day]) + P[day]);
    }
    return cac = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    T = vi(N + 1), P = vi(N + 1);
    cache = vi(N + 1, -1);
    RP(i, N) {
        cin >> T[i + 1] >> P[i + 1];
    }

    cout << go(1) << endl;

    return 0;
}
