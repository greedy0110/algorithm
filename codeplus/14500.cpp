//
// Created by 신승민 on 2021/07/23.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'

int N, M;
int B[501][501];

int dir[19][3][2] = {
        {{0, 1}, {0,  2}, {0,  3}},
        {{1, 0}, {2,  0}, {3,  0}},

        {{1, 0}, {0,  1}, {1,  1}},

        {{1, 0}, {2,  0}, {2,  1}},
        {{1, 0}, {0,  1}, {0,  2}},
        {{0, 1}, {1,  1}, {2,  1}},
        {{0, 1}, {0,  2}, {-1, 2}},
        {{0, 1}, {-1, 1}, {-2, 1}},
        {{1, 0}, {1,  1}, {1,  2}},
        {{1, 0}, {2,  0}, {0,  1}},
        {{0, 1}, {0,  2}, {1,  2}},

        {{1, 0}, {1,  1}, {2,  1}},
        {{0, 1}, {-1, 1}, {-1, 2}},
        {{0, 1}, {1,  1}, {1,  2}},
        {{1, 0}, {0,  1}, {-1, 1}},

        {{0, 1}, {0,  2}, {1,  1}},
        {{1, 0}, {2,  0}, {1,  1}},
        {{0, 1}, {0,  2}, {-1, 1}},
        {{0, 1}, {-1, 1}, {1,  1}},
};

bool in_board(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    RP(i, N) RP(j, M) cin >> B[i][j];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 0; d < 19; d++) {
                int i1 = i + dir[d][0][0];
                int j1 = j + dir[d][0][1];
                if (!in_board(i1, j1)) continue;

                int i2 = i + dir[d][1][0];
                int j2 = j + dir[d][1][1];
                if (!in_board(i2, j2)) continue;

                int i3 = i + dir[d][2][0];
                int j3 = j + dir[d][2][1];
                if (!in_board(i3, j3)) continue;

                ans = max(ans, B[i][j] + B[i1][j1] + B[i2][j2] + B[i3][j3]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
