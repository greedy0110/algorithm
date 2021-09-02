//
// Created by 신승민 on 2021/04/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 987654321
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

int N, M;
int S, E;
vvpii G;
vi parent;

int dijkstra() {
    // 최소 힙을 만든다.
    priority_queue<pii, vpii, greater<>> q;
    vi dist(N, 1e9);
    vb visited(N, false);
    parent = vi(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    dist[S] = 0;
    q.push({0, S});

    while (!q.empty()) {
        int cd = q.top().first;
        int u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &p : G[u]) {
            int v = p.first;
            int c = p.second;

            if (dist[v] > cd + c) {
                dist[v] = cd + c;
                parent[v] = u;
                q.push({dist[v], v});
            }
        }
    }

    return dist[E];
}

vi find_route(int u) {
    if (parent[u] == u) {
        vi ans;
        ans.push_back(u);
        return ans;
    }
    vi ans = find_route(parent[u]);
    ans.push_back(u);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    G = vvpii(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
    }
    cin >> S >> E;
    S--;
    E--;

    int ans = dijkstra();
    vi ans2 = find_route(E);

    cout << ans << endl;
    cout << ans2.size() << endl;
    for (int d : ans2) cout << d + 1 << " ";
    cout << endl;

    return 0;
}
