#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int V,E;
vector<vi> g;
vi discovered;
vb isCutVertex;
int counter;

int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];

    int children = 0;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i];
        if (discovered[there] == -1) {
            children++;
            int subtree = findCutVertex(there, false);
            if (!isRoot && subtree >= discovered[here]) {
                // subtree can't reach upper here. so, here is cut vertex.
                isCutVertex[here] = true;
            }
            ret = min(ret, subtree);
        }
        else {
            ret = min(ret, discovered[there]);
        }
    }

    if (isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}

int main() {
    cin >> V >> E;

    g = vector<vi>(V, vi());
    discovered = vi(V, -1);
    isCutVertex = vb(V, false);
    counter = 0;

    for (int i=0; i<E; i++) {
        int a,b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=0; i<V; i++) {
        if (discovered[i] == -1) {
            findCutVertex(i, true);
        }
    }

    vi cutVertexs;
    for (int i=0; i<V; i++) {
        if (isCutVertex[i]) cutVertexs.push_back(i);
    }
    
    cout << cutVertexs.size() << endl;
    for (int i=0; i< cutVertexs.size(); i++) {
        cout << cutVertexs[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
