//
// Created by 신승민 on 2021/08/07.
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

struct C {
public:
    int name;
    int one, two, three;

    void give(int pre) {
        if (pre == 3) three++;
        else if (pre == 2) two++;
        else one++;
    }

    int total() const {
        return one + 2 * two + 3 * three;
    }

    bool operator==(const C &other) const {
        return one == other.one && two == other.two && three == other.three;
    }

    bool operator<(const C &other) const {
        if (total() != other.total()) {
            return total() < other.total();
        }

        if (three != other.three) {
            return three < other.three;
        }

        if (two != other.two) {
            return two < other.two;
        }

        return one < other.one;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<C> cs(3, {0, 0, 0, 0});
    for (int i = 1; i <= 3; i++) cs[i-1].name = i;
    RP(_, N) {
        int a, b, c;
        cin >> a >> b >> c;
        cs[0].give(a);
        cs[1].give(b);
        cs[2].give(c);
    }

    sort(all(cs));

    if (cs[2] == cs[1]) {
        cout << 0 << " " << cs[2].total() << endl;
    } else {
        cout << cs[2].name << " " << cs[2].total() << endl;
    }

    return 0;
}
