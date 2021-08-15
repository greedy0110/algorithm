//
// Created by 신승민 on 2021/08/15.
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

vvi A;
int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in_board(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

bool go(int mn, int mx) {
    if (A[0][0] < mn || A[0][0] > mx) {
        return false;
    }

    // x, y, min
    queue<pair<int, int>> q;
    vector<vb> visited(N, vb(N, false));
    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];

            if (!in_board(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (A[nx][ny] < mn || A[nx][ny] > mx) continue;
            visited[nx][ny] = true;

            q.push({nx, ny});
        }
    }

    return visited[N - 1][N - 1];
}

bool go2(int diff) {
    for (int mn = 0; mn + diff <= 200; mn++) {
        if (go(mn, mn + diff)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A = vvi(N, vi(N));
    RP(x, N) {
        RP(y, N) {
            cin >> A[x][y];
        }
    }

    int left = 0, right = 200;
    while (left != right) {
        int mid = (left + right) / 2;
        if (go2(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;

    return 0;
}
