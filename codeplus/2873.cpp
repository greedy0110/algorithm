//
// Created by 신승민 on 2021/08/07.
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

void append(string &str, char ch, int n) {
    RP(_, n) str.push_back(ch);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int A[1000][1000];
    cin >> N >> M;
    RP(x, N) RP(y, M) cin >> A[x][y];

    if (N % 2 != 0) {
        for (int x = 0; x < N; x++) {
            for (int i = 0; i < M - 1; i++)
                cout << (x % 2 == 0 ? 'R' : 'L');
            if (x != N - 1) cout << "D";
        }
    } else if (M % 2 != 0) {
        for (int y = 0; y < M; y++) {
            for (int i = 0; i < N - 1; i++)
                cout << (y % 2 == 0 ? 'D' : 'U');
            if (y != M - 1) cout << "R";
        }
    } else {
        // 1. 이동하지 않을 칸 고르기.
        int nox, noy;
        int temp_min = 10000;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if ((x + y) % 2 == 1) { // 검은 칸에서만 고르자.
                    if (A[x][y] < temp_min) {
                        temp_min = A[x][y];
                        nox = x;
                        noy = y;
                    }
                }
            }
        }

        int ax = 0, ay = 0, bx = N - 1, by = M - 1;
        string s, sb;
        // 2. A, B의 위치를 각각 변경시키자.
        // 3. 이동하려는 두개의 칸에 이동 불가능한 칸이 없다면...
        // 4. 행 에 대해서, 열에 대해서...
        // 최종적으로 2*2 문제로 변경한다.
        while (bx - ax > 1) {
            if (ax / 2 != nox / 2) {
                append(s, 'R', M - 1);
                append(s, 'D', 1);
                append(s, 'L', M - 1);
                append(s, 'D', 1);
                ax += 2;
            }

            if (bx / 2 != nox / 2) {
                append(sb, 'R', M - 1);
                append(sb, 'D', 1);
                append(sb, 'L', M - 1);
                append(sb, 'D', 1);
                bx -= 2;
            }
        }

        while (by - ay > 1) {
            if (ay / 2 != noy / 2) {
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                ay += 2;
            }
            if (by / 2 != noy / 2) {
                append(sb, 'D', 1);
                append(sb, 'R', 1);
                append(sb, 'U', 1);
                append(sb, 'R', 1);
                by -= 2;
            }
        }

        assert(bx - ax == 1 && by - ay == 1);

        if (by == noy) {
            append(s, 'D', 1);
            append(s, 'R', 1);
        } else {
            append(s, 'R', 1);
            append(s, 'D', 1);
        }
        reverse(all(sb));
        cout << s + sb << endl;
    }

    return 0;
}
