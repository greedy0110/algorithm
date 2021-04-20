//
// Created by 신승민 on 2021/04/19.
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

string A, B;
// len[i][j] 는 A 의 문자열에서 prefix i 자리, B 의 문자열에서 prefix j 자리 만큼일 때, LCS 길이이다.
int len[1001][1001];
int order[1001][1001];

void lcs() {
    int N = A.size();
    int M = B.size();

    repeat(i, N + 1) {
        len[i][0] = 0;
    }
    repeat(i, M + 1) {
        len[0][i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) {
                len[i][j] = len[i - 1][j - 1] + 1; // 실제로, lcs 의 길이가 늘어나는 것.
                order[i][j] = 3; // A[i], B[j] 는 같고, 이걸 출력하면 됨.
            } else if (len[i - 1][j] >= len[i][j - 1]) {
                len[i][j] = len[i - 1][j]; // Ai-1 과 Bj 의 lcs 를 비교하는 것임.
                order[i][j] = 2;
            } else {
                len[i][j] = len[i][j - 1];
                order[i][j] = 1;
            }
        }
    }
}

void print_lcs(int i, int j) {
    if (i == 0 || j == 0) return;
    if (order[i][j] == 3) {
        print_lcs(i - 1, j - 1);
        cout << A[i - 1];
    } else if (order[i][j] == 2) print_lcs(i - 1, j);
    else if (order[i][j] == 1) print_lcs(i, j - 1);
}

void solve() {
    cin >> A >> B;

    lcs();

    int pa = A.size();
    int pb = B.size();

    cout << len[pa][pb] << endl;
    if (len[pa][pb] != 0) {
        print_lcs(pa, pb);
        cout << endl;
    }
}