// 사이클에 속하는 모든 노드
// 나가는 간선이 없는 노드
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

li order;
vb visited;
Graph g, gt;

int N, M;

vi dfs(const Graph& g, int u, bool orderFlag) {
    visited[u] = true;

    vi nodes;
    nodes.push_back(u);
    for (auto it = g[u].cbegin(); it != g[u].cend(); it++) {
        if (!visited[*it]) {
            auto ret = dfs(g, *it, orderFlag);
            nodes.insert(nodes.end(), ret.begin(), ret.end());
        }
    }

    if (orderFlag) order.push_front(u);

    return nodes;
}

void dfsAll() {
    visited = vb(N, false);
    order.clear();
    for (int i=0; i<N; i++) {
        if (!visited[i]) dfs(g, i, true);
    }
}

// scc의 사이즈가 2라면 모든node는 포함.
// Gscc는 DAG이다.
// 따라서 사이즈가 1인 노드는 나가는 노드가 없을 경우에만 포함된다.
// Gscc에서도 나가는 간선이 있는 scc는 포함되지 않는다.
// 따라서 Gscc를 구하고, Gscc에서 나가는 간선이 없는 node를 모으면 된다.
void scc() {
    dfsAll();

    visited = vb(N, false);
    vi ans;
    for (auto it = order.cbegin(); it != order.cend(); it++) {
        if (!visited[*it]) {
            auto ret = dfs(gt, *it, false);

            // ret의 결과 노드가, 나가는 방향에 ret의 결과노드 이외의 노드가 있다면, 무시한다.
            set<int> inGroup, out;
            for (auto jt = ret.cbegin(); jt != ret.cend(); jt++) {
                inGroup.insert(*jt);
                for (int i=0; i<g[*jt].size(); i++) {
                    out.insert(g[*jt][i]);
                }
            }

            set<int> setDiff;
            set_difference(out.begin(), out.end(), inGroup.begin(), inGroup.end(), inserter(setDiff, setDiff.end()));

            // setDiff가 empty면 ans에 기록한다.
            if (setDiff.empty()) {
                ans.insert(ans.end(), ret.begin(), ret.end());
            }
        }
    }

    sort(ans.begin(), ans.end());

    // 들어오는 간선 없는 노드는 제외한다.
    // gt에서 나가는 간선이 없는 노드는 제외한다.

    for (auto it = ans.cbegin(); it != ans.cend(); it++) {
        cout << *it + 1 << " ";
    }
    cout << endl;
}

int main() {
    string nm;
    getline(cin, nm);
    while (nm != "0") {
        string es; getline(cin, es);
        
        istringstream iss(nm);
        iss >> N >> M;

        g = Graph(N, vi());
        gt = Graph(N, vi());

        istringstream ies(es);
        for (int i=0; i<M; i++) {
            int a, b; ies >> a >> b; a--; b--;
            g[a].push_back(b);
            gt[b].push_back(a);
        }

        scc();
        
        getline(cin, nm);
    }
    return 0;
}
