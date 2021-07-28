//
// Created by 신승민 on 2021/07/29.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int A[5][5];
    RP(i, N) {
        string temp;
        cin >> temp;
        RP(j, M) {
            A[i][j] = temp[j] - '0';
        }
    }

    int ans = 0;
    // 0: 가로, 1: 세로
    for (int b = 0; b < (1 << (M * N)); b++) {
        int sum = 0;

        // 가로 체크
        for (int i = 0; i < N; i++) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                int k = i * M + j;
                if ((b & (1 << k)) == 0) {
                    cur = 10 * cur + A[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        // 세로 체크
        for (int j = 0; j < M; j++) {
            int cur = 0;
            for (int i = 0; i < N; i++) {
                int k = i * M + j;
                if ((b & (1 << k)) > 0) {
                    cur = 10 * cur + A[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
