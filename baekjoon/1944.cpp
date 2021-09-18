//
// Created by 신승민 on 2021/09/18.
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

class UnionFind {
public:
    vi parents;

    UnionFind(int n) {
        parents = vi(n);
        RP(i, n) parents[i] = i;
    }

    int find(int u) {
        if (u == parents[u]) return u;
        return parents[u] = find(parents[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        parents[u] = v;
    }
};

struct Edges {
    int w, u, v;

    bool operator<(Edges &a) { return w < a.w; }
};

int n, m;
vector<Edges> es;
vector<pair<int, int>> pos;
vvi board;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in_board(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bfs(int s) {
    auto &sp = pos[s];
    queue<pair<int, int>> q;
    vvi dist(n, vi(n, -1));
    dist[sp.first][sp.second] = 0;
    q.push({sp.first, sp.second});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        int cd = dist[cx][cy];

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (in_board(nx, ny)) {
                if (board[nx][ny] == 1) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = cd + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < m + 1; i++) {
        if (i == s) continue;
        auto &ip = pos[i];
        es.push_back({dist[ip.first][ip.second], s, i});
    }
}

void kruscal() {
    for (int i = 0; i < m + 1; i++) {
        bfs(i);
    }
    sort(all(es));
    UnionFind nf(m + 1);
    int mst = 0;
    for (auto &e: es) {
        if (e.w == -1) {
            cout << -1 << endl;
            return;
        }
        if (!nf.same(e.u, e.v)) {
            nf.merge(e.u, e.v);
            mst += e.w;
        }
    }
    cout << mst << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    board = vvi(n, vi(n));
    RP(x, n) {
        string temp;
        cin >> temp;
        RP(y, n) {
            int tile = temp[y] - '0';
            if (temp[y] == 'S' || temp[y] == 'K') {
                tile = 0;
                pos.emplace_back(x, y);
            }
            board[x][y] = tile;
        }
    }
    assert(pos.size() == m + 1);

    kruscal();

    return 0;
}
