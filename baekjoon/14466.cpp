//
// Created by 신승민 on 2021/11/10.
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
typedef pair<int, int> pii;

int N, totalCowNum, R;
vector<vb> visited;
vvi farm;
vvi edges;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int toIndex(int x, int y) {
    return N * x + y;
}

bool exist(int fromX, int fromY, int toX, int toY) {
    int fromIndex = toIndex(fromX, fromY);
    int index = toIndex(toX, toY);

    for (int it : edges[fromIndex]) {
        if (it == index) return true;
    }
    return false;
}

bool valid(int cx, int cy, int nx, int ny) {
    if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (!visited[nx][ny]) {
            if (!exist(cx, cy, nx, ny) && !exist(nx, ny, cx, cy)) {
                return true;
            }
        }
    }
    return false;
}

int met(int sx, int sy) {
    queue<pii> q;
    visited = vector<vb>(N, vb(N, false));
    q.push({sx, sy});
    visited[sx][sy] = true;
    int numMetCow = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if (farm[cx][cy] == 1) numMetCow++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (valid(cx, cy, nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return numMetCow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> totalCowNum >> R;
    farm = vvi(N, vi(N, 0));
    edges = vvi(N * N);

    RP(_, R) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int index1 = toIndex(a, b);
        int index2 = toIndex(c, d);
        edges[index1].push_back(index2);
        edges[index2].push_back(index1);
    }

    RP(_, totalCowNum) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        farm[x][y] = 1;
    }

    int grossDistant = 0;
    RP(x, N) {
        RP(y, N) {
            if (farm[x][y] == 1) grossDistant += (totalCowNum - met(x, y));
        }
    }
    cout << grossDistant / 2 << endl;

    return 0;
}
