#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N = 9;
    int myints[] = {10, 10, 10, 20, 20, 20, 25, 30, 31};
    vector<int> v(myints, myints + N);

    // 값이 있는 경우.
    {
        // 값이 하나 있는 경우, 해당 값의 index 반환
        int low_idx_1 = lower_bound(v.begin(), v.end(), 31) - v.begin();
        printf("%d\n", low_idx_1); // 6

        // 값이 여러개 있는 경우, 여러개의 값 중 첫번째의 index 반환
        int low_idx = lower_bound(v.begin(), v.end(), 20) - v.begin();
        printf("%d\n", low_idx); // 3
    }

    // 값이 없는 경우.
    {
        // 모든 원소보다 작은 값을 찾는 경우, 0 반환
        int low_idx_sml = lower_bound(v.begin(), v.end(), -1) - v.begin();
        printf("%d\n", low_idx_sml); // 0

        // 모든 원소보다 큰 값을 찾는 경우, N 반환
        int low_idx_bgr = lower_bound(v.begin(), v.end(), 100) - v.begin();
        printf("%d\n", low_idx_bgr); // 9

        // 그 이외의 경우, 해당 값보다 큰 값의 index 반환
        int low_idx_mid = lower_bound(v.begin(), v.end(), 18) - v.begin();
        printf("%d\n", low_idx_mid); // 3
    }

    return 0;
}