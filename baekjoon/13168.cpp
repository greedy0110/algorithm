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

int n, r, m;
const int INF = 1e9;
map<string, int> indices;

void floyd(vvi &dist) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int cost(vvi &dist, vi &order) {
    int ret = 0;
    for (int i = 0; i < m - 1; i++) {
        ret += dist[order[i]][order[i + 1]];
    }
    return ret;
}

bool is_free(string &trans) {
    return trans == "Mugunghwa" || trans == "ITX-Saemaeul" || trans == "ITX-Cheongchun";
}

bool is_half(string &trans) {
    return trans == "S-Train" || trans == "V-Train";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r;
    r *= 2;// 50% 할인을 정수로 처리하기 위한 처리.
    int i = 0;
    RP(_, n) {
        string city;
        cin >> city;
        if (indices.find(city) == indices.end()) {
            indices[city] = i++;
        }
    }
    n = i;
    cin >> m;
    vi order(m);
    RP(i, m) {
        string city;
        cin >> city;
        order[i] = indices[city];
    }

    vvi dist(n, vi(n, INF)), ticket(n, vi(n, INF));

    int k;
    cin >> k;
    RP(_, k) {
        string trans, from, to;
        int c, u, v;
        cin >> trans >> from >> to >> c;
        u = indices[from];
        v = indices[to];
        c *= 2; // 50% 할인을 정수로 처리하기 위한 처리.

        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);

        if (is_free(trans)) {
            ticket[v][u] = ticket[u][v] = 0;
        } else if (is_half(trans)) {
            ticket[u][v] = min(ticket[u][v], c / 2);
            ticket[v][u] = min(ticket[v][u], c / 2);
        } else {
            ticket[u][v] = min(ticket[u][v], c);
            ticket[v][u] = min(ticket[v][u], c);
        }
    }

    floyd(dist);
    floyd(ticket);

    if (cost(ticket, order) + r < cost(dist, order)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
