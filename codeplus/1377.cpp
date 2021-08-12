//
// Created by 신승민 on 2021/08/12.
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
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pii> A(N);
    RP(i, N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(all(A));
    int ans = 0;
    RP(i, N) {
        ans = max(ans, A[i].second - i);
    }
    ans++;
    cout << ans << endl;

    return 0;
}
