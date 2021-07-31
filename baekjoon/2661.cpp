//
// Created by 신승민 on 2021/07/31.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int A[81];
int N;

bool check(int index) {
    for (int len = 2; 2 * len <= (index + 1); len++) {
        bool bad = true;
        for (int i = 0; i < len; i++) {
            bad = bad && (A[index - i] == A[index - i - len]);
        }
        if (bad) return false;
    }
    return true;
}

bool go(int index) {
    if (index == N) {
        RP(i, N) cout << A[i];
        cout << endl;
        return true;
    }

    int x = A[index - 1];
    int p1 = x % 3 + 1, p2 = (x + 1) % 3 + 1;
    if (p1 > p2) swap(p1, p2);
    A[index] = p1;
    if (check(index)) if (go(index + 1)) return true;
    A[index] = p2;
    if (check(index)) if (go(index + 1)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A[0] = 1;
    go(1);

    return 0;
}
