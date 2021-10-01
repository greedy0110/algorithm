//
// Created by 신승민 on 2021/10/01.
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

vvi cap;
vvi g;

void set_single(int u, int v) {
    cap[u][v] = 1;
    g[u].push_back(v);
    g[v].push_back(u);
}

void set_cap(int u, int v) {
    int u_ = u + 1, v_ = v + 1;
    set_single(u, u_);
    set_single(v, v_);
    set_single(u_, v);
    set_single(v_, u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int t = 1;; t++) {
        int num_students, num_intersections;
        cin >> num_students >> num_intersections;
        if (num_students == 0 && num_intersections == 0) break;

        int NODE_SIZE = 2 * num_intersections;
        int s = 0, e = 3, max_flow = 0;
        g = vvi(NODE_SIZE);
        cap = vvi(NODE_SIZE, vi(NODE_SIZE, 0));
        vvi flow(NODE_SIZE, vi(NODE_SIZE, 0));

        cin.ignore();
        RP(i, num_intersections) {
            int u = 2 * i;
            string line;
            getline(cin, line);
            vi vs;
            for (size_t pos = line.find(' '); pos != string::npos; pos = line.find(' ')) {
                vs.push_back(stoi(line.substr(0, pos)) - 1);
                line.erase(0, pos + 1);
            }
            vs.push_back(stoi(line) - 1);

            for (int j : vs) {
                int v = 2 * j;
                set_cap(u, v);
            }
        }
        cap[s][s + 1] = cap[e - 1][e] = 1e9;

        while (true) {
            vi prev(NODE_SIZE, -1);
            prev[s] = s;
            queue<int> q;
            q.push(s);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (prev[v] != -1) continue;
                    if (cap[u][v] - flow[u][v] <= 0) continue;
                    prev[v] = u;
                    q.push(v);
                }
            }
            if (prev[e] == -1) break;
            for (int v = e; v != s; v = prev[v]) {
                int u = prev[v];
                flow[u][v] += 1;
                flow[v][u] -= 1;
            }
            max_flow += 1;
            if (max_flow == num_students) break;
        }


        cout << "Case " << t << ":" << endl;
        if (max_flow >= num_students) {
            // 소스에서 싱크로 유량이 흐르는 중인 경로를 찾고, 지운다.
            while (true) {
                vi prev(NODE_SIZE, -1);
                prev[s] = s;
                queue<int> q;
                q.push(s);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : g[u]) {
                        if (prev[v] != -1) continue;
                        if (flow[u][v] <= 0) continue; // 흐는 중인게 없다면 무시.
                        prev[v] = u;
                        q.push(v);
                    }
                }

                if (prev[e] == -1) break;
                vi route;
                for (int v = e; v != s; v = prev[v]) {
                    int a = v / 2;
                    if (route.empty()) route.push_back(a);
                    else if (route.back() != a) route.push_back(a);
                    int u = prev[v];
                    flow[u][v] -= 1;
                    flow[v][u] += 1;
                }
                reverse(all(route));
                for (int r : route) {
                    cout << r + 1 << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
        cout << endl;
    }

    return 0;
}
