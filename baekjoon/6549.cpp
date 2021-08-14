//
// Created by 신승민 on 2021/08/14.
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
    ll la = go(left, mid);
    ll ra = go(mid + 1, right);
    ll ans = max(la, ra);

    ll w = 1;
    ll h = A[mid];
    int li = mid - 1, ri = mid + 1;
    while (left <= li && ri <= right) {
        if (A[li] < A[ri]) {
            w++;
            h = min(h, A[ri]);
            ri++;
        } else {
            w++;
            h = min(h, A[li]);
            li--;
        }
        ans = max(ans, h * w);
    }

    while (left <= li) {
        w++;
        h = min(h, A[li]);
        li--;
        ans = max(ans, h * w);
    }

    while (ri <= right) {
        w++;
        h = min(h, A[ri]);
        ri++;
        ans = max(ans, h * w);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> N;
        if (N == 0) break;
        A = vector<ll>(N);
        RP(i, N) cin >> A[i];
        cout << go(0, N - 1) << endl;
    }

    return 0;
}
