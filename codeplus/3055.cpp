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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char A[50][50];
    int N, M;
    cin >> N >> M;
    vvi W(N, vi(M, -1));
    vvi T(N, vi(M, -1));

    queue<pair<int, int>> wq;

    pair<int, int> s, e;
    RP(x, N) {
        string temp;
        cin >> temp;
        RP (y, M) {
            char l = A[x][y] = temp[y];
            if (l == '*') {
                W[x][y] = 0;
                wq.push({x, y});
            } else if (l == 'D') {
                e = {x, y};
            } else if (l == 'S') {
                s = {x, y};
            }
        }
    }

    while (!wq.empty()) {
        int cx, cy;
        tie(cx, cy) = wq.front();
        wq.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (A[nx][ny] == 'X' || A[nx][ny] == 'D') continue;
            if (W[nx][ny] != -1) continue;

            W[nx][ny] = W[cx][cy] + 1;
            wq.push({nx, ny});
        }
    }

    queue<pair<int, int>> q;
    T[s.first][s.second] = 0;
    q.push(s);

    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        int ct = T[cx][cy];
        q.pop();

        if (cx == e.first && cy == e.second) {
            cout << ct << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
            if (A[nx][ny] == 'X') continue;
            if (T[nx][ny] != -1) continue;
            if (W[nx][ny] != -1 && W[nx][ny] <= ct + 1) continue;

            T[nx][ny] = ct + 1;
            q.push({nx, ny});
        }
    }

    cout << "KAKTUS" << endl;

    return 0;
}
