// edge (a, b)가 주어진다.
// topology sort결과를 출력한다.
//
// node: 32,000개
// edge: 100,000개
//
// adjacent list representation
// dfs
//      time complexity: O(V+E)

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

using namespace std;
// [N][M] 크기의 2차원 배열 선언 할 수 있어야함.

int N, M;
vector<vector<int> > G;
vector<bool> visited;
list<int> topology;

void dfs_visit(int u) {
    visited[u] = true;
    for (int i=0; i<G[u].size(); i++) {
        int nxt = G[u][i];
        if (!visited[nxt]) dfs_visit(nxt);
    }
    topology.push_front(u);
}

void topology_sort() {
    for (int i=0; i<N; i++) {
        if (!visited[i]) dfs_visit(i);
    }

    // 끝나는대로 리스트의 앞에 둔다.
    // 리스트를 처음부터 출력한다.
    for (auto it = topology.cbegin(); it != topology.cend(); it++) {
        cout << *it + 1 << " ";
    }
}

int main() {
    cin >> N >> M;

    G = vector<vector<int> >(N, vector<int>());
    visited = vector<bool>(N, false);

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    topology_sort();
    return 0;
}
