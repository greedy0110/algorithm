//
// Created by 신승민 on 2021/09/02.
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        // * set<int>는 중복을 허용하지 않으므로 안된다.
        multiset<int> q;
        int N;
        cin >> N;
        char cmd;
        int param;
        while (N--) {
            cin >> cmd >> param;
            if (cmd == 'I') {
                q.insert(param);
            } else {
                if (q.empty()) continue;
                if (q.size() == 1) {
                    q.clear();
                    continue;
                }

                if (param == -1) {
                    // 최솟값 삭제.
                    q.erase(q.begin());
                } else {
                    // 최댓값 삭제
                    q.erase(--q.end());
                }
            }
        }
        if (q.empty()) cout << "EMPTY" << endl;
        else {
            cout << *(--q.end()) << " " << *q.begin() << endl;
        }
    }

    return 0;
}
