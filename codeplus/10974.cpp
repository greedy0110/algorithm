//
// Created by 신승민 on 2021/07/27.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

void print(const vector<int> &a) {
    for (int c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    RP(i, N) A[i] = i + 1;
    do {
        print(A);
    } while (next_permutation(all(A)));

    return 0;
}
