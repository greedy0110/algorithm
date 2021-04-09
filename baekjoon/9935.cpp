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
string boom;

class BoomStack {
public:
    char arr[1000001];
    string boom;
    int top = 0;

    void push(char s) {
        arr[top++] = s;

        if (boom.size() <= top) {
            bool trigger = true;
            for (int i = 0; i < boom.size(); i++) {
                if (boom[i] != arr[top - boom.size() + i]) {
                    trigger = false;
                    break;
                }
            }

            if (trigger) {
                top -= boom.size();
            }
        }
    }

    bool empty() {
        return top == 0;
    }
};

void solve() {
    cin >> str >> boom;

    BoomStack stack;

    stack.boom = boom;

    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++) {
        stack.push(str[i]);
    }

    if (stack.empty()) {
        cout << "FRULA" << endl;
    } else {
        for (int i = 0; i < stack.top; i++) {
            printf("%c", stack.arr[i]);
        }
        printf("\n");
    }
}
