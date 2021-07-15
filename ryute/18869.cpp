//
// Created by 신승민 on 2021/07/15.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> normalize(const vector<int> &u) {
    vector<int> v(u), ans(u.size(), 0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < u.size(); i++) {
        int dist = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
        ans[i] = dist;
    }
    return ans;
}

void printVec(const vector<int> &u) {
    for (int a : u) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<vector<int>> U;

    for (int i = 0; i < M; i++) {
        vector<int> u(N);
        for (int j = 0; j < N; j++) cin >> u[j];
        u = normalize(u);
        U.push_back(u);
    }

    sort(U.begin(), U.end());
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i < M; i++) {
        if (U[i - 1] == U[i]) cnt++;
        else {
            if (cnt >= 2) {
                ans += cnt * (cnt - 1) / 2;
            }
            cnt = 1;
        }
    }
    if (cnt >= 2) {
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
