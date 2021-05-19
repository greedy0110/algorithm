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
vb vtd;

vi parse(const string &sss) {
    vi ret;

    int prev = 0;
    for (int i = 0; i <= sss.length(); i++) {
        if (i == sss.length() || sss[i] == ' ') {
            ret.emplace_back(stoi(sss.substr(prev, i - prev)));
            prev = i + 1;
        }
    }

    return ret;
}

void dfs1(int u) {
    vtd[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];

        if (vtd[v]) continue;
        dfs1(v);
    }
    tpl.push_back(u);
}

void dfs(int st) {
    queue<int> q;

    q.push(st);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];

            if (vtd[v]) continue;
            vtd[v] = true;
            q.push(v);
        }
    }
}

void solve() {
    cin >> N >> M;

    G = vvi(N + 1);
    vtd = vb(N + 1, false);

    string temp;
    getline(cin, temp);
    repeat(_, M) {
        getline(cin, temp);
        vi pi = parse(temp);

        for (int i = 2; i < pi.size(); i++) {
            G[pi[i - 1]].push_back(pi[i]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (vtd[i]) continue;
        dfs1(i);
    }

    reverse(all(tpl));

    vb bv = vb(N + 1, false);
    // 뒤로가는 간선이 있으면 안돼.
    for (int i = 1; i < tpl.size(); i++) {
        bv[tpl[i]] = true;

        for (int j = 0; j < G[tpl[i]].size(); j++) {
            int v = G[tpl[i]][j];

            if (bv[v]) {
                // 역방향 간선이 존재.
                cout << 0 << endl;
                return;
            }
        }
    }

    for (int u : tpl) {
        cout << u << endl;
    }
}
