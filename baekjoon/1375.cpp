//
// Created by 신승민 on 2021/05/19.
//

#include <bits/stdc++.h>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 100000007
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

vvi G;
int N, M;
vi tpl;

bool can_reach(int u, int v) {
    vb visited(N + 1, false);

    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty()) {
        int uu = q.front();
        q.pop();

        for (int i = 0; i < G[uu].size(); i++) {
            int vv = G[uu][i];

            if (vv == v) return true;
            if (visited[vv])continue;

            q.push(vv);
            visited[vv] = true;
        }
    }

    return false;
}

vb tv;

void dfs(int u) {
    tv[u] = true;

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (tv[v]) continue;
        dfs(v);
    }

    tpl.push_back(u);
}

void solve() {
    cin >> N >> M;

    G = vvi(N + 1);
    tv = vb(N + 1, false);

    repeat(_, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (tv[i]) continue;
        dfs(i);
    }
    reverse(all(tpl));

    int Q;
    cin >> Q;
    repeat(_, Q) {
        int a, b;
        cin >> a >> b;

        if (!can_reach(a, b) && !can_reach(b, a)) {
            cout << "gg ";
            continue;
        }

        for (int t : tpl) {
            if (t == a || t == b) {
                cout << t << " ";
                break;
            }
        }
    }
    cout << endl;
}
