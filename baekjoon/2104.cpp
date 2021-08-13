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

ll go(int left, int right) {
    if (left == right) {
        return A[left] * A[left];
    }

    int mid = (left + right) / 2;
    ll la = go(left, mid), ra = go(mid + 1, right);
    ll ans = max(la, ra);

    int li = mid - 1, ri = mid + 1;
    ll temp_sum = A[mid];
    ll temp_min = A[mid];
    while (left <= li && ri <= right) {
        if (A[li] < A[ri]) {
            temp_sum += A[ri];
            temp_min = min(temp_min, A[ri]);
            ans = max(ans, temp_sum * temp_min);
            ri++;
        } else {
            temp_sum += A[li];
            temp_min = min(temp_min, A[li]);
            ans = max(ans, temp_sum * temp_min);
            li--;
        }
    }

    while (left <= li) {
        temp_sum += A[li];
        temp_min = min(temp_min, A[li]);
        ans = max(ans, temp_sum * temp_min);
        li--;
    }

    while (ri <= right) {
        temp_sum += A[ri];
        temp_min = min(temp_min, A[ri]);
        ans = max(ans, temp_sum * temp_min);
        ri++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    A = vector<ll>(N);
    RP(i, N) cin >> A[i];
    cout << go(0, N - 1) << endl;

    return 0;
}
