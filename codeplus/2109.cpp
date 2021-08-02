//
// Created by 신승민 on 2021/08/01.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MAX_DAY = 10000;
    int N;
    cin >> N;
    vvi lectures(MAX_DAY + 1);
    RP(i, N) {
        int p, d;
        cin >> p >> d;
        lectures[d].push_back(p);
    }

    priority_queue<int> pq;
    int ans = 0;
    for (int day = MAX_DAY; day >= 1; day--) {
        for (int p : lectures[day]) pq.push(p);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
