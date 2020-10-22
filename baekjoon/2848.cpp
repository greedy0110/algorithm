#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<si> Graph;
typedef vector<bool> vb;

map<string, vi> prefixDic;
Graph g = Graph(26, si());
vb checkList = vb(26, false);
list<int> top;
vi visited = vi(26, 0);
bool hasCycle = false;

void dfs(int u, bool flag = false) {
    visited[u] = 1;

    for (auto it = g[u].cbegin(); it != g[u].cend(); it++) {
        if (visited[*it] == 1) {
            // 싸이클 존재
            hasCycle = true;
        }
        if (visited[*it] == 0) {
            dfs(*it, flag);
        }
    }

    if (flag) {
        top.push_front(u);
    }
    visited[u] = 2;
}

void dfsAll() {
    for (int i=0; i<26; i++) {
        if (checkList[i] && visited[i] == 0) {
            dfs(i, true);
        }
    }
}

void topology() {
    visited = vi(26,0);
    // topology[0] 으로 dfs를 호출하면 
    // 한번에 모든 노드를 방문하면 방문 순서의 역순으로 출력
    // 한번에 모든 노드를 방문 못하면 ?
    
    dfs(top.front());

    bool allNodeVisited = true;
    for (int i=0; i<26; i++) {
        if (checkList[i] && visited[i] == 0) {
            allNodeVisited = false;
            break;
        }
    }

    if (allNodeVisited) {
        for (auto it = top.begin(); it != top.end(); it++) {
            cout << (char)(*it+'a');
        }
        cout << endl;
    }
    else {
        cout << "?" << endl;
    }
}

int main() {
    // 나오는 알파벳 모두 하나의 정점으로 생각할 수 있다.
    // word가 들어오면.
    // "" -> w, "w" -> o, "wo" -> r, "wor" -> d
    int N; cin >> N;
    for (int i=0; i<N; i++){
        string word; cin >> word;
        for (int j=0; j<word.size();j++) {
            checkList[word[j]-'a'] = true;
            prefixDic[word.substr(0, j)].push_back(word[j]-'a');
        }
    }

    for (auto it = prefixDic.begin(); it != prefixDic.end(); it++) {
        vi order = it->second;
        // order 의 요소가 1개 일 때? 아무런 연결이 없다.
        int prev = order[0];
        for (int i=1; i<order.size(); i++) {
            if (prev == order[i]) continue;
            g[prev].insert(order[i]);
            prev = order[i];
        }
    }

    dfsAll();
    if (hasCycle) {
        cout << "!" << endl;
    }
    else {
        topology();
    }

    // 사이클이 있으면 !
    return 0;
}
