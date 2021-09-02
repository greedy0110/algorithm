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

    int N, M;
    cin >> N >> M;
    vector<string> num_index(N + 1);
    map<string, int> str_index;
    RP(i, N) {
        cin >> num_index[i + 1];
        str_index[num_index[i + 1]] = i + 1;
    }
    RP(_, M) {
        string quest;
        cin >> quest;
        if ('0' <= quest[0] && quest[0] <= '9') {
            cout << num_index[stoi(quest)] << endl;
        } else {
            cout << str_index[quest] << endl;
        }
    }

    return 0;
}
