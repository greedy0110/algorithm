//
// Created by 신승민 on 2021/08/10.
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

ll ans = 0;
vi A;
int N;

void mergesort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);

    // [left, mid] 정렬되어 있다.
    // [mid+1, right] 정렬되어 있다.
    int left_cnt = mid - left + 1;
    int li = left, ri = mid + 1, ki = 0;
    vi temp(right - left + 1);
    while (li <= mid && ri <= right) {
        if (A[li] <= A[ri]) { // 같을 때는 샐 필요 없으므로, 왼쪽 것에서 먼저 뺀다.
            temp[ki++] = A[li++];
            left_cnt--;
        } else {
            ans += (ll) left_cnt;
            temp[ki++] = A[ri++];
        }
    }

    while (li <= mid) temp[ki++] = A[li++];
    while (ri <= right) {
        ans += (ll) left_cnt;
        temp[ki++] = A[ri++];
    }

    for (int i = 0; i < ki; i++) A[left + i] = temp[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vi(N);
    RP(i, N) cin >> A[i];

    mergesort(0, N - 1);
    cout << ans << endl;

    return 0;
}
