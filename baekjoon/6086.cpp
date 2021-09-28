//
// Created by 신승민 on 2021/09/28.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int, int> pii;

const int NODE_SIZE = 2 * ('Z' - 'A' + 1);

int to_index(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + ('Z' - 'A' + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vvi currency(NODE_SIZE, vi(NODE_SIZE, 0));
    vvi flow(NODE_SIZE, vi(NODE_SIZE, 0));

    RP(_, n) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int u = to_index(a), v = to_index(b);
        currency[u][v] = currency[v][u] += c;
    }

    int s = to_index('A'), e = to_index('Z'), total = 0;
    while (true) {
        // 증강 범위를 찾음. (증강? 흐를 수 있는 flow 가 있는가? 있으면 방문한다.)
        vi prev(NODE_SIZE, -1);
        queue<int> q;
        prev[s] = s;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < NODE_SIZE; v++) {
                if (currency[u][v] == 0) continue;
                if (prev[v] != -1) continue;
                if (currency[u][v] - flow[u][v] == 0) continue; // 남은 용량이 없으면 나가리.
                prev[v] = u;
                q.push(v);
            }
        }

        if (prev[e] == -1) break;

        // 루트 중에서 가장 작은 가능한 flow 만큼만 흐를 수 있다.
        int possible_flow = 1e9;
        for (int i = e; i != s; i = prev[i]) {
            int j = prev[i];
            possible_flow = min(possible_flow, currency[j][i] - flow[j][i]);
        }

        // 루트에 흘려주자.
        for (int i = e; i != s; i = prev[i]) {
            int j = prev[i];
            flow[j][i] += possible_flow;
            flow[i][j] -= possible_flow; // 역방향으로는 줄여주자.
        }

        total += possible_flow;
    }

    cout << total << endl;

    return 0;
}
