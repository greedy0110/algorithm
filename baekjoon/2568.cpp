//
// Created by 신승민 on 2021/08/15.
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

struct Cable {
    int s, e;

    bool operator<(const Cable &other) const {
        return s < other.s;
    }
};

vi ans;
vector<Cable> S;

void merge(int left, int right) {
    // S의 Cable을 정렬하는 함수.
    // si < sj 순 정렬은 이미 되어있고.
    // ei < ej 순 정렬.
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;
    merge(left, mid);
    merge(mid + 1, right);

    int i = left, j = mid + 1, k = 0;
    vector<Cable> temp(right - left + 1);
    while (i <= mid && j <= right) {
        // s 는 같은 값이 존재하지 않음.
        if (S[i].e > S[j].e) {
            ans.push_back(S[i].s);
            temp[k++] = S[j++];
        } else {
            temp[k++] = S[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = S[i++];
    }

    while (j <= right) {
        temp[k++] = S[j++];
    }

    for (int c = 0; c < k; c++) {
        S[left + c] = temp[c];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    S = vector<Cable>(N);
    RP(i, N) {
        cin >> S[i].s >> S[i].e;
    }
    sort(all(S));

    merge(0, N - 1);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}
