//
// Created by 신승민 on 2021/08/17.
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

int N, M;
vi A;

bool go(int size) {
    int cnt = 1;
    int sum = 0;
    for (int a : A) {
        if (a + sum > size) {
            cnt++;
            sum = a;
        } else {
            sum += a;
        }
    }

    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    A = vi(N);

    // 블루레이 크기
    int left = 0, right = 0, ans, mid;
    RP(i, N) {
        cin >> A[i];
        left = max(left, A[i]); // 각각을 1개의 블루레이로 담을 때
        right += A[i]; // 1개에 다 담아야 할 때
    }

    while (left <= right) {
        mid = (left + right) / 2;
        if (go(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
