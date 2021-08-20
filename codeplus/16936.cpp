//
// Created by 신승민 on 2021/08/20.
//

#include <bits/stdc++.h>

using namespace std;

#define RP(i, X) for (int i=0; i<((X)); i++)
#define all(X) begin((X)), end((X))
#define endl '\n'
#define custom_pq(X) priority_queue<X, vector<X>, X>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef long long ll;

set<ll> B;
int N;
vector<ll> A;

bool go() {
    assert(!A.empty());
    if (A.size() == N) {
        for (ll a : A) cout << a << " ";
        cout << endl;
        return true;
    }

    ll prev = A.back();
    // 나3
    if (prev % 3 == 0) {
        ll next = prev / 3;
        if (B.find(next) != B.end()) {
            // B에 있는 값만 추가될 수 있고.
            A.push_back(next);
            if (go()) return true;
            A.pop_back();
        }
    }

    // 곱2
    ll next = prev * 2;
    if (B.find(next) != B.end()) {
        // B에 있는 값만 추가될 수 있고.
        A.push_back(next);
        if (go()) return true;
        A.pop_back();
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 나3, 곱2 -> 문제 특성상, 중복되는 숫자가 없다.
    // 각 원소를 시작으로 배열을 만들다가. 절대 진행될 수 없다면, 진행을 멈춘다.
    cin >> N;
    RP(i, N) {
        ll temp;
        cin >> temp;
        B.insert(temp);
    }

    for (ll b : B) {
        assert(A.empty());
        A.push_back(b);
        if (go()) {
            break;
        }
        A.pop_back();
    }

    return 0;
}
