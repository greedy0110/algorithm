// ITA의 SCC를 구현해보는 연습문제
//
// pseudo code
//   G에 대한 dfs를 하며 종료시간을 기록한다.
//   G^t에 대한 dfs를 하는데, 방문 순서는 종료시간의 하향순으로 한다.
//   각 루트노드에 대한 dfs가 SCC이다. sccCount++, 하고 해당 루트를 포함해 순회한 노드를 기록한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > Graph;

// implement function to get G^t
// topology를 구한다.

int V, E;
Graph G;
Graph Gt;
vector<bool> visited;
list<int> topology;

// 방문한 모든 노드를 반환해야 한다.
vi dfs_visit(const Graph& G, int u, bool topologyFlag) {
    vi visit;
    visit.push_back(u);
    visited[u] = true;
    for (int i=0; i<G[u].size(); i++) {
        int nxt = G[u][i];
        if (!visited[nxt]) {
            auto ret = dfs_visit(G, nxt, topologyFlag);
            visit.insert(visit.end(), ret.begin(), ret.end());
        }
    }
    if (topologyFlag)
        topology.push_front(u);
    return visit;
}

void topology_sort() {
    visited = vector<bool>(V, false);
    for (int i=0; i<V; i++) {
      if (!visited[i])
        dfs_visit(G, i, true);
    }
}

bool sccs_sort(vi i, vi j) {
    return i[0] < j[0];
}

void scc() {
// Gt에 대한 dfs 수행, topology 리스트 순서대로 방문
    visited = vector<bool>(V, false);
    vector<vi> sccs;

    for (auto it = topology.cbegin(); it != topology.cend(); it++) {
        if (!visited[*it]) {
            auto ret = dfs_visit(Gt, *it, false);
            sort(ret.begin(), ret.end());
            sccs.push_back(ret);
        }
    }

    cout << sccs.size() << endl;

    sort(sccs.begin(), sccs.end(), sccs_sort);

    // sccs내부가 정점 순으로 정렬 되어 있어야 한다.
    for (auto it = sccs.cbegin(); it != sccs.cend(); it++) {
        for (auto j = it->cbegin(); j != it->cend(); j++) {
            cout << *j + 1 << " ";
        }
        cout << -1 << endl;
    }
}

int main() {
    cin >> V >> E;

    G = Graph(V, vector<int>());
    Gt = Graph(V, vector<int>());

    for (int i=0; i<E; i++) {
       int a, b; cin >> a >> b; a--; b--;
       G[a].push_back(b);
       Gt[b].push_back(a);
    }

    topology_sort();
    scc();
    return 0;
}
