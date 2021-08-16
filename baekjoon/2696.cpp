//
// Created by 신승민 on 2021/08/16.
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

    int T;
    cin >> T;
    while (T--) {
        // 큰 수가 먼저 오는 우선순위 큐
        priority_queue<int> small;
        // 작은 수가 먼저 오는 우선순위 큐
        priority_queue<int, vector<int>, greater<>> big;

        int N;
        cin >> N;
        vi ans;
        RP(i, N) {
            int A;
            cin >> A;

            if (small.empty()) small.push(A);
            else if (small.top() >= A) {
                small.push(A);
                if (small.size() > big.size() + 1) {
                    big.push(small.top());
                    small.pop();
                }
            } else {
                big.push(A);
                if (big.size() > small.size()) {
                    small.push(big.top());
                    big.pop();
                }
            }

            assert(small.size() <= big.size() + 1);

            if (i % 2 == 0) {
                ans.push_back(small.top());
            }
        }

        cout << ans.size() << endl;
        int cnt = 0;
        for (int a : ans) {
            cnt++;
            cout << a << " ";
            if (cnt == 10) {
                cout << endl;
                cnt = 0;
            }
        }
        if (cnt != 0) cout << endl;
    }

    return 0;
}
