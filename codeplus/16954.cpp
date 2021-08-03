//
// Created by 신승민 on 2021/08/03.
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

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char A[8][8];
    int V[8][8][9] = {};
    RP(i, 8) {
        string temp;
        cin >> temp;
        RP(j, 8) {
            A[i][j] = temp[j];
        }
    }

    queue<tuple<int, int, int>> q;
    V[7][0][0] = 1;
    q.push({7, 0, 0});

    while (!q.empty()) {
        int cx, cy, ct;
        tie(cx, cy, ct) = q.front();
        q.pop();

        if (cx == 7 && cy == 7) {
            cout << 1 << endl;
            return 0;
        }

        for (int d = 0; d < 9; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || 8 <= nx || ny < 0 || 8 <= ny) continue;
            int nt = min(ct + 1, 8);
            if (V[nx][ny][nt] != 0) continue;
            if (nx - ct >= 0 && A[nx - ct][ny] == '#') continue; // 현재 시간에 nx, ny는 벽이 있음.
            if (nx - nt >= 0 && A[nx - nt][ny] == '#') continue; // 다음 시간에 벽이 있을 것임. 불가능함.

            V[nx][ny][nt] = 1;
            q.push({nx, ny, nt});
        }
    }
    cout << 0 << endl;

    return 0;
}
