//
// Created by 신승민 on 2021/04/14.
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

void solve() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        cout << 1 << endl;
        return;
    }

    vi bt(N + 1);

    queue<pii> q;
    si s;
    q.push(make_pair(0, N));
    s.insert(N);

    int ans = -1;
    // 이미 queue 에 들어가 본적 있는 친구면 안 넣어도 된다.
    while (!q.empty()) {
        auto value = q.front();
        q.pop();

        int d = value.first;
        int n = value.second;

        if (n == 0) continue;
        if (n == 1) {
            ans = d;
            break;
        }

        if (n % 3 == 0 && s.find(n / 3) == s.end()) {
            q.push(make_pair(d + 1, n / 3));
            s.insert(n / 3);
            bt[n / 3] = n;
        }
        if (n % 2 == 0 && s.find(n / 2) == s.end()) {
            q.push(make_pair(d + 1, n / 2));
            s.insert(n / 2);
            bt[n / 2] = n;
        }
        if (s.find(n - 1) == s.end()) {
            q.push(make_pair(d + 1, n - 1));
            s.insert(n - 1);
            bt[n - 1] = n;
        }
    }

    cout << ans << endl;

    vi r;

    r.push_back(1);
    int parent = bt[1];

    while (parent != N) {
        r.push_back(parent);
        parent = bt[parent];
    }

    r.push_back(N);

    for (int i = r.size() - 1; i >= 0; i--) {
        cout << r[i] << " ";
    }
    cout << endl;
}
