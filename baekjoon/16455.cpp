//
// Created by 신승민 on 2021/08/08.
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

int choose_pivot(int start, int end) {
    return (start + end) / 2;
}

int partition(vi &a, int start, int end) {
    int pivotIndex = choose_pivot(start, end);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[end]);
    int storeIndex = start, i = start;
    while (i < end) {
        if (a[i] < pivotValue) {
            swap(a[i], a[storeIndex]);
            storeIndex++;
        }
        i++;
    }
    swap(a[storeIndex], a[end]);
    return storeIndex;
}

int quick_select(vi &a, int start, int end, int k) {
    int pivot = partition(a, start, end);
    if (pivot == k) {
        return a[k];
    } else if (k < pivot) {
        return quick_select(a, start, pivot - 1, k);
    } else {
        return quick_select(a, pivot + 1, end, k);
    }
}

int kth(std::vector<int> &a, int k) {
    int ans = 0;
    ans = quick_select(a, 0, a.size(), k);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
