//
// Created by 신승민 on 2021/09/14.
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

int n, m;
const int INF = 1e9;

vi bfs(int s, vvi &g, vb &visited) {
    vi ret;
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ret.push_back(cur);

        for (int v : g[cur]) {
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }

    return ret;
}

vvi find_group(vvi &g) {
    vb visited(n + 1, false);
    vvi groups;
    for (int s = 1; s <= n; s++) {
        if (visited[s]) continue;
        groups.push_back(bfs(s, g, visited));
    }
    return groups;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vvi g(n + 1);
    vvi dist(n + 1, vi(n + 1, INF));
    RP(_, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    auto groups = find_group(g);
    cout << groups.size() << endl;
    vi ans;
    for (auto &group : groups) {
        if (group.size() == 1) ans.push_back(group.front());
        else {
            int an, ans_min = INF;
            // group 에 속하는 i, j 사이만 비교하자.
            // dist[i][j] 는 항상 존재한다.
            // j를 대표로 할 때를 가정한다. dist[i][j] -> 그럴 때 i참석자의 의사전달시간.
            // 즉 각 j를 할 때마다. dist[i][j]의 최대값을 찾고, 해당 값이 가장 작은 j를 찾는 것이 최종 목적.
            for (int j : group) {
                int temp_max = -1;
                for (int i : group) {
                    if (i == j) continue;
                    assert(dist[i][j] != INF);
                    temp_max = max(temp_max, dist[i][j]);
                }
                if (ans_min > temp_max) {
                    ans_min = temp_max;
                    an = j;
                }
            }
            ans.push_back(an);
        }
    }
    sort(all(ans));
    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}
