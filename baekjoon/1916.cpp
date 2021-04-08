//
// Created by 신승민 on 2021/04/09.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

#define all(X) begin((X)), end((X))
#define endl '\n'
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define repeat(i, X) for (int i=0; i<((X)); i++)
#define BIG 987654321
#define SUPER_BIG 987654321123456789

typedef long long ll;
typedef vector<int> vi;
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
    cin.tie(nullptr);
    solve();
    return 0;
}

vvpii wG;
int N, M;

ll dijkstar(int src, int tgt) {
    vll dist(N + 1, SUPER_BIG);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> min_q;

    dist[src] = 0;
    min_q.push(make_pair(0, src));

    while (!min_q.empty()) {
        pii value = min_q.top();
        min_q.pop();

        int d = value.first;
        int u = value.second;

        for (int i = 0; i < wG[u].size(); i++) {
            int v = wG[u][i].first;
            int w = wG[u][i].second;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                min_q.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[tgt];
}

void solve() {
    cin >> N >> M;

    wG = vvpii(N + 1);

    repeat(_, M) {
        int a, b, c;
        cin >> a >> b >> c;

        wG[a].push_back(make_pair(b, c));
    }

    int a, b;
    cin >> a >> b;

    cout << dijkstar(a, b) << endl;
}
