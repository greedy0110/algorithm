//
// Created by 신승민 on 2021/08/13.
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

vector<ll> A;
int N;

ll go(int left, int right) {
    if (left == right) {
        return A[left];
    }

    int mid = (left + right) / 2;
    ll la = go(left, mid), ra = go(mid + 1, right);
    ll ans = max(la, ra);

    int li = mid - 1, ri = mid + 1;
    ll w = 1;
    ll h = A[mid];
    while (left <= li && ri <= right) {
        if (A[li] < A[ri]) { // ri 쪽으로 확장
            h = min(h, A[ri]);
            w++;
            ri++;
        } else {
            h = min(h, A[li]);
            w++;
            li--;
        }
        ans = max(ans, h * w);
    }

    while (left <= li) {
        h = min(h, A[li]);
        w++;
        li--;
        ans = max(ans, h * w);
    }

    while (ri <= right) {
        h = min(h, A[ri]);
        w++;
        ri++;
        ans = max(ans, h * w);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vector<ll>(N);
    RP(i, N) cin >> A[i];

    cout << go(0, N - 1) << endl;

    return 0;
}
