#include <vector>
#include <cmath>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;

int G[26][26] = {{0}};
vb checkList = vb(26,false);
vi visited = vi(26, 0);
bool hasCycle = false;
list<int> topology;

void dfs(int u, bool topologyFlag) {
    visited[u] = 1;

    for (int i=0; i<26; i++) {
        if (G[u][i] == 1 && visited[i] == 1) {
            hasCycle = true;
        }
        if (G[u][i] == 1 && visited[i] == 0) {
            dfs(i, topologyFlag);
        }
    }

    if (topologyFlag) topology.push_front(u);
    visited[u] = 2;
}

void dfsAll() {
    visited = vi(26,0);
    for (int i=0; i<26; i++) {
        if (checkList[i] && visited[i] == 0) {
            dfs(i, true);
        }
    }
}

int main() {
    int N; cin >> N;
    vector<string> words = vector<string>(N);

    for (int i=0; i<N; i++) {
        cin >> words[i];

        for (int j=0; j<words[i].size(); j++) {
            checkList[words[i][j]-'a'] = true;
        }
    }

    for (int j=1; j<N; j++) {

        int i = j-1, len = min(words[i].size(), words[j].size());

        // words[j]가 words[i]와 같지 않고 prefix라면, !를 출력해야한다.
        if (words[j].size() < words[i].size()) {
            if (words[i].substr(0, words[j].size()) == words[j]) {
                cout << "!" << endl;
                return 0;
            }
        }

        for (int k=0; k<len; k++) {
            if (words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                G[a][b] = 1;
                break;
            }
        }
    }

    dfsAll();
    if (hasCycle) {
        cout << "!" << endl;
    }
    else {
        // topology 순서대로 prev -> cur 순행 간선이 있으면 그대로 출력 아니면 ?
        int prev = topology.front();
        bool onlyOne = true;
        for (auto it = topology.begin(); it != topology.end(); it++) {
            if (it == topology.begin()) continue;

            if (G[prev][*it] == 0) {
                onlyOne = false;
                cout << "?" << endl;
                break;
            }
            prev = *it;
        }

        if (onlyOne) {
            for (auto it = topology.begin(); it != topology.end(); it++) {
                cout << (char)(*it+'a');
            }
            cout << endl;
        }
    }
}
