//
// Created by 신승민 on 2021/04/21.
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

string A, B, C;
int I, J, K;
int M[101][101][101];

string ext(int order[][101], const string &A, int i, int j, ostringstream &ret) {
    if (i == 0 || j == 0) return "";
    if (order[i][j] == 3) {
        ext(order, A, i - 1, j - 1, ret);
        ret << A[i - 1];
    } else if (order[i][j] == 2) {
        ext(order, A, i - 1, j, ret);
    } else if (order[i][j] == 1) {
        ext(order, A, i, j - 1, ret);
    }
}

string lcs(const string &A, const string &B) {
    int N = A.size();
    int M = B.size();

    int C[101][101];
    int order[101][101];

    repeat(i, N + 1) {
        C[i][0] = 0;
    }

    repeat(i, M + 1) {
        C[0][i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                order[i][j] = 3;
            } else if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j];
                order[i][j] = 2;
            } else {
                C[i][j] = C[i][j - 1];
                order[i][j] = 1;
            }
        }
    }

    vc ret;
    while (N != 0 && M != 0) {
        if (order[N][M] == 3) {
            ret.push_back(A[N - 1]);
            N--;
            M--;
        } else if (order[N][M] == 2) {
            N--;
        } else {
            M--;
        }
    }

    reverse(all(ret));
    string ans(all(ret));

    return ans;
}

void lcs3() {
    repeat(i, I + 1) {
        repeat(j, J + 1) {
            M[i][j][0] = 0;
        }
    }
    repeat(j, J + 1) {
        repeat(k, K + 1) {
            M[0][j][k] = 0;
        }
    }

    repeat(i, I + 1) {
        repeat(k, K + 1) {
            M[i][0][k] = 0;
        }
    }

    for (int i = 1; i <= I; i++) {
        for (int j = 1; j <= J; j++) {
            for (int k = 1; k <= K; k++) {
                char ai = A[i - 1];
                char bj = B[j - 1];
                char ck = C[k - 1];

                if (ai == bj && bj == ck) {
                    M[i][j][k] = M[i - 1][j - 1][k - 1] + 1;
                } else {
                    M[i][j][k] = max(M[i - 1][j][k], max(M[i][j - 1][k], M[i][j][k - 1]));
                }
            }
        }
    }
}

void solve() {
    cin >> A >> B >> C;
    I = A.size();
    J = B.size();
    K = C.size();

    lcs3();

    cout << M[I][J][K] << endl;
}