//
// Created by 신승민 on 2021/11/09.
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

int toIndex(int x, int y) {
    return 1000 * x + y;
}

struct Node {
    int h, x, y, order;

    Node() {
        h = INT_MAX;
        x = y = order = -1;
    }
};

class Uf {
private:
    vi parents;
    vector<Node> nodes;

    Node high(Node a, Node b) {
        if (a.h < b.h) {
            return a;
        } else if (b.h < a.h) {
            return b;
        } else if (a.order < b.order) {
            return a;
        } else {
            return b;
        }
    }

public:
    Uf() {
        parents = vi(1000000);
        RP(i, 1000000) parents[i] = i;
        nodes = vector<Node>(1000000);
    }

    int root(int u) {
        if (parents[u] == u) return u;
        return parents[u] = root(parents[u]);
    }

    void merge(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        parents[u] = v;

        nodes[v] = high(nodes[u], nodes[v]);
    }

    void setNode(Node node) {
        int u = toIndex(node.x, node.y);
        int ur = root(u);
        nodes[ur] = high(nodes[ur], node);
    }

    void print(int x, int y) {
        int index = 1000 * x + y;
        int p = root(index);
        cout << nodes[p].x + 1 << " " << nodes[p].y + 1 << endl;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int board[1000][1000], N, M, Q, water[1000][1000] = {};
    cin >> N >> M >> Q;
    RP(i, N) RP(j, M) cin >> board[i][j];

    Uf uf;
    RP(order, Q) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        int index = toIndex(x, y);

        Node node;
        node.x = x;
        node.y = y;
        node.h = board[x][y] - c;
        node.order = order;
        uf.setNode(node);
        water[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (water[nx][ny] == 1) {
                    int nIndex = toIndex(nx, ny);
                    uf.merge(index, nIndex);
                }
            }
        }
        uf.print(x, y);
        board[x][y] -= c;
    }

    return 0;
}
