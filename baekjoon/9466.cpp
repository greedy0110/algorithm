//
// Created by 신승민 on 2021/06/02.
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
typedef vector<vc> vvc;
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

int T;
int N;
vi s;
vb in_team;
vi visited;

const int NO = 0, ING = 1, DONE = 2;

void make_team(int u, int v) {
    do {
        in_team[u] = true;
        u = s[u];
    } while (u != v);
    in_team[u] = true;
}

void bfs(int u) {
    visited[u] = ING;
    int next = s[u];
    if (visited[next] == NO) {
        bfs(next);
    } else if (visited[next] == ING) {
        make_team(next, u);
    }
    visited[u] = DONE;
}

void solve() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        s = vi(N);
        in_team = vb(N, false);
        visited = vi(N, NO);

        for (int i = 0; i < N; i++) {
            scanf("%d", &s[i]);
            s[i]--;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i] == NO) {
                bfs(i);
            }
        }

        printf("%ld\n", count(all(in_team), false));
    }
}
