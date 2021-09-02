//
// Created by 신승민 on 2021/09/02.
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

int cnt[2] = {};
int N;
int A[128][128];

int lookup(int x, int y, int size) {
    int kind = A[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (A[i][j] != kind) return -1;
        }
    }
    return kind;
}

void go(int x, int y, int size) {
    assert(size != 1);
    int next = size / 2;
    for (int i = x; i < x + size; i += next) {
        for (int j = y; j < y + size; j += next) {
            int kind = lookup(i, j, next);
            if (kind != -1) cnt[kind]++;
            else go(i, j, next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    RP(i, N) RP(j, N) cin >> A[i][j];
    int kind = lookup(0, 0, N / 2);
    if (kind != -1) cnt[kind]++;
    else go(0, 0, N);
    for (int i = 0; i < 2; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}
