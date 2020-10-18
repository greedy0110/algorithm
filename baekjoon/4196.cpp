#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


typedef vector<int> vi;
typedef vector<vector<int> > Graph;

int C, N, M;
Graph G;
Graph Gt;
vector<bool> visited;
list<int> topology;

void dfs_visit(const Graph& G, int u, bool topologyFlag) {
    visited[u] = true;
    for (int i=0; i<G[u].size(); i++) {
        int nxt = G[u][i];
        if (!visited[nxt]) {
            dfs_visit(G, nxt, topologyFlag);
        }
    }
    if (topologyFlag)
        topology.push_front(u);
}

void topology_sort() {
    visited = vector<bool>(N, false);
    topology.clear();

    for (int i=0; i<N; i++) {
      if (!visited[i])
        dfs_visit(G, i, true);
    }
}

void scc() {
    // Gt에 대한 dfs 수행, topology 리스트 순서대로 방문
    visited = vector<bool>(N, false);
    int size = 0;
    for (auto it = topology.cbegin(); it != topology.cend(); it++) {
        if (!visited[*it]) {
            dfs_visit(G, *it, false);
            size++;
        }
    }

    cout << size << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> C;

    for (int t=0; t<C; t++) {
        cin >> N >> M;

        G = Graph(N, vector<int>());
        Gt = Graph(N, vector<int>());

        for (int i=0; i<M; i++) {
           int a, b; cin >> a >> b; a--; b--;
           G[a].push_back(b);
           Gt[b].push_back(a);
        }

        topology_sort();
        scc();
    }
    return 0;
}
