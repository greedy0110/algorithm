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

int R, C;
char A[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int go(int x, int y, vector<bool> &h, int depth) {
    int ans = depth;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || R <= nx || ny < 0 || C <= ny) continue;
        int idx = A[nx][ny] - 'A';
        if (h[idx]) continue;
        h[idx] = true;
        ans = max(ans, go(nx, ny, h, depth + 1));
        h[idx] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    RP(x, R) {
        string temp;
        cin >> temp;
        RP(y, C) A[x][y] = temp[y];
    }
    vb h(26, false);
    h[A[0][0] - 'A'] = true;
    cout << go(0, 0, h, 1) << endl;

    return 0;
}
