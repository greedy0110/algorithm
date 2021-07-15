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
    for (int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for (int a : A) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
