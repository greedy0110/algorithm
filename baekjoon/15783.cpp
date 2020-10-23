// 위상 정렬한 이후
// 위상 정렬 순서대로 dfs를 하며, count를 증가시킨다.
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> Graph;
typedef list<int> li;
typedef vector<bool> vb;

Graph g;
int N, M;
li order;
vb visited;

void dfs(int u, bool orderFlag) {
    visited[u] = true;

    for (auto it = g[u].cbegin(); it != g[u].cend(); it++) {
        if (!visited[*it]) dfs(*it, orderFlag);
    }

    if (orderFlag) order.push_front(u);
}

void dfsAll() {
    visited = vb(N, false);
    for (int i=0; i<N; i++) {
        if (!visited[i]) dfs(i, true);
    }
}

void solve() {
    dfsAll();
    visited = vb(N, false);
    int ans = 0;
    for (auto it = order.cbegin(); it != order.cend(); it++) {
        if (!visited[*it]) {
            dfs(*it, false);
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> N >> M;

    g = Graph(N, vi());

    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    solve();
    return 0;
}
