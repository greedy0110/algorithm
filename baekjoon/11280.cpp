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

            int prev = ret[0]/2;
            for (int i=1; i<ret.size(); i++) {
                if (ret[i]/2 == prev) {
                    cout << "0" << endl;
                    return;
                }
                prev = ret[i]/2;
            }
        }
    }

    // sccs 의 요소에 i, -i가 함께 있으면 0 출력, 아니면 1 출력
    cout << "1" << endl;
}

int main() {
    cin >> V >> E;
    V *= 2;

    G = Graph(V, vector<int>());
    Gt = Graph(V, vector<int>());

    for (int i=0; i<E; i++) {
        int a, b; cin >> a >> b;
        
        int ga, gb, mga, mgb;
        if (a > 0) {
            ga = 2*(a-1);
            mga = ga + 1;
        }
        else {
            ga = -2*(1+a) + 1;
            mga = ga - 1;
        }
        if (b > 0) {
            gb = 2*(b-1);
            mgb = gb + 1;
        }
        else {
            gb = -2*(1+b) + 1;
            mgb = gb - 1;
        }

        G[mga].push_back(gb);
        G[mgb].push_back(ga);
        Gt[gb].push_back(mga);
        Gt[ga].push_back(mgb);
    }

    topology_sort();
    scc();

    return 0;
}
