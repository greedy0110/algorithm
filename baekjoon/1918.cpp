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

    int prev_priority = 1;
    int prev_index = -2;
    int wrap_index = -2;
    vector<Token> compressed_tokens;
    // operation priority 에 따라서 token 을 묶자.
    for (int i = 0; i < tokens.size(); i++) {
        char op = tokens[i].op;
        if (op == 0) continue;

        int priority;
        if (op == '+' || op == '-') priority = 1;
        if (op == '*' || op == '/') priority = 2;

        if (priority == 2 && prev_priority == 1) {
            prev_index = i;
            wrap_index = -1;
        } else if (priority == 1 && prev_priority == 2) {
            wrap_index = i;

            string ret = tokens[prev_index - 1].str;
            for (int j = prev_index; j < wrap_index; j += 2) {
                ret += tokens[j + 1].str + tokens[j].op;
            }
            compressed_tokens.push_back(Token{ret, 0});
            compressed_tokens.push_back(tokens[i]);
        } else if (prev_priority == 1) {
            compressed_tokens.push_back(tokens[i - 1]);
            compressed_tokens.push_back(tokens[i]);
        }

        prev_priority = priority;
    }

    if (wrap_index == -1) {
        // prev는 있는데 wrap이 안되었다면? prev_index-1 ~ 끝까지 compress 대상
        string ret = tokens[prev_index - 1].str;
        for (int j = prev_index; j < tokens.size(); j += 2) {
            ret += tokens[j + 1].str + tokens[j].op;
        }
        compressed_tokens.push_back(Token{ret, 0});
    } else {
        compressed_tokens.push_back(tokens.back());
    }

    string ret = compressed_tokens[0].str;
    for (int i = 1; i < compressed_tokens.size(); i += 2) {
        ret += compressed_tokens[i + 1].str + compressed_tokens[i].op;
    }

    return ret;
}

void solve() {
    string str;
    cin >> str;
    cout << postfix_notation(str) << endl;
}