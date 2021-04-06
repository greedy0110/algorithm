//
// Created by 신승민 on 2021/04/06.
//

#include <cstdio>
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
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2
#define BIG 987654321

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<string> vs;
typedef priority_queue<int, vi, greater<>> mq;
typedef priority_queue<pii, vpii, greater<>> mpq;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

int M, N;
vi arr;

void aa(vi &visited) {
    if (visited.size() == M) {
        for (int i = 0; i < M; i++) {
            if (visited[i]) printf("%d ", visited[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (find(all(visited), arr[i]) == visited.end()) {
            visited.push_back(arr[i]);
            aa(visited);
            visited.pop_back();
        }
    }
}

void solve() {
    cin >> N >> M;
    arr = vi(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(all(arr));

    vi visited = vi();
    aa(visited);
}
