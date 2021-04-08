//
// Created by 신승민 on 2021/04/05.
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

struct Token {
    string str;
    char op;
};

string postfix_notation(const string &str) {
    cout << str << endl;
    if (str.size() == 1) {
        return str;
    }

    stack<int> stack;
    vector<Token> tokens;
    int start;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '(':
                stack.push(i);
                break;
            case ')':
                start = stack.top();
                stack.pop();
                if (stack.empty()) {
                    string chunk = str.substr(start + 1, i - start - 1);
                    tokens.push_back(Token{postfix_notation(chunk), 0});
                    cout << tokens.back().str << endl;
                }
                break;
            case '/':
            case '*':
            case '+':
            case '-':
                if (stack.empty()) {
                    tokens.push_back(Token{"", str[i]});
                }
                break;
            default:
                if (stack.empty()) {
                    tokens.push_back(Token{str.substr(i, 1), 0});
                }
        }
    }

    string ret = tokens[0].str;
    for (int i = 1; i < tokens.size(); i += 2) {
        ret += tokens[i + 1].str + tokens[i].op;
    }

    return ret;
}

void solve() {
    cout << postfix_notation("A*(B+C)") << endl;
}