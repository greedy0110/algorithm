//
// Created by 신승민 on 2021/07/15.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(A);

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    for (int i = 0; i < N; i++) {
        int dist = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
