//
// Created by 신승민 on 2021/08/24.
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

int R, C;

void printboard(vector<vector<char>> &board) {
    cout << 1 << endl;
    RP(r, R) {
        RP(c, C) {
            cout << board[r][c];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    vector<vector<char>> A(R, vector<char>(C));

    queue<pair<int, int>> q;
    int wolf = 0, sheep = 0;

    RP(r, R) {
        string temp;
        cin >> temp;
        RP(c, C) {
            A[r][c] = temp[c];

            if (A[r][c] == 'S') {
                q.push({r, c});
                sheep++;
            } else if (A[r][c] == 'W') {
                wolf++;
            }
        }
    }

    if (sheep == 0 || wolf == 0) {
        printboard(A);
        return 0;
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = cr + dx[k], nc = cc + dy[k];

            if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
            if (A[nr][nc] == 'W') {
                cout << 0 << endl;
                return 0;
            }
            if (A[nr][nc] == '.') {
                A[nr][nc] = 'D';
            }
        }
    }

    printboard(A);


    return 0;
}
