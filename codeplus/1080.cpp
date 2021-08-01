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

    int A[50][50], B[50][50];
    int N, M;
    cin >> N >> M;
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) A[i][j] = temp[j] - '0';
    }
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) B[i][j] = temp[j] - '0';
    }

    int cnt = 0;
    for (int x = 0; x < N - 2; x++) {
        for (int y = 0; y < M - 2; y++) {
            if (A[x][y] != B[x][y]) {
                for (int i = x; i < x + 3; i++) {
                    for (int j = y; j < y + 3; j++) {
                        A[i][j] = 1 - A[i][j];
                    }
                }
                cnt++;
            }
        }
    }

    RP(x, N) RP(y, M) {
            if (A[x][y] != B[x][y]) {
                cout << -1 << endl;
                return 0;
            }
        }

    cout << cnt << endl;
    return 0;
}
