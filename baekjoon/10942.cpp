//
// Created by 신승민 on 2021/05/07.
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

vector<vi> cpd;
int S[2001];
int N;

// O(N^2) 번 호출, 내부 로직은 O(N) 시간이 걸림.
int is_pd(int i, int j) {
    int &ans = cpd[i][j];
    if (ans != 0) {
        return (ans == 1);
    }

    // O(N)
    while (i < j) {
        if (S[i] != S[j]) {
            ans = 2;
            return 0;
        }
        i++;
        j--;
    }
    ans = 1;
    return 1;
}

void solve() {
    scanf("%d", &N);
    repeat(i, N) scanf("%d", &S[i]);

    cpd = vector<vi>(N, vi(N, 0));

    int M;
    scanf("%d", &M);
    repeat(_, M) {
        int s, e;
        scanf("%d %d", &s, &e);
        s--;
        e--;
        printf("%d\n", is_pd(s, e));
    }
}

