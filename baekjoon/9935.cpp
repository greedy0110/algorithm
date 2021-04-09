//
// Created by 신승민 on 2021/04/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

char str[1000001];
char boom[37];

void solve() {
    cin >> str >> boom;

    int boom_len = strlen(boom);
    int str_len = strlen(str);

    while (true) {
        vi booms;

        for (int i = 0; i < str_len - boom_len + 1; i++) {
            if (str[i] == boom[0]) {
                bool trigger = true;

                int j;
                for (j = 1; j < boom_len; j++) {
                    if (str[i + j] != boom[j]) {
                        trigger = false;
                        break;
                    }
                }

                if (trigger) booms.push_back(i);
            }
        }

        if (booms.empty()) break;

        int prev_boom = booms[0];
        int k = 0;

        for (int j = 0; j < prev_boom; j++) {
            str[k] = str[j];
            k++;
        }

        for (int i = 1; i < booms.size(); i++) {
            int boom_index = booms[i];

            for (int j = prev_boom + boom_len; j < boom_index; j++) {
                str[k] = str[j];
                k++;
            }

            prev_boom = boom_index;
        }

        for (int i = prev_boom + boom_len; i < str_len; i++) {
            str[k] = str[i];
            k++;
        }

        str_len -= booms.size() * boom_len;
    }

    if (str_len <= 0) {
        printf("FRULA\n");
    } else {
        for (int i = 0; i < str_len; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
}
