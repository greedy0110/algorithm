//
// Created by 신승민 on 2021/07/27.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N;
int A[11];
int S[11][11];

bool check(int i) {
    int sum = 0;
    for (int j = i; j >= 0; j--) {
        sum += A[j];
        if (S[j][i] == 0) {
            if (sum != 0) return false;
        } else if (S[j][i] < 0) {
            if (sum >= 0) return false;
        } else if (S[j][i] > 0) {
            if (sum <= 0) return false;
        }
    }
    return true;
}

bool go(int i) {
    if (i == N) return true;

    if (S[i][i] == 0) {
        A[i] = 0;
        return check(i) && go(i + 1);
    }

    for (int j = 1; j <= 10; j++) {
        A[i] = S[i][i] * j;
        if (check(i) && go(i + 1)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    string raw;
    cin >> raw;

    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            char s = raw[k++];
            if (s == '+') S[i][j] = 1;
            else if (s == '-') S[i][j] = -1;
            else S[i][j] = 0;
        }
    }

    go(0);

    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;

    return 0;
}
