#include <iostream>
#include <vector>
#include <algorithm>
#include "assert.h"

using namespace std;

vector<int> inorder = vector<int>(100000);
vector<int> postorder = vector<int>(100000);

void preorder(int inS, int inE, int postS, int postE) {
    assert(postE - postS == inE - inS);

    if (inE - inS <= 0) {
        return;
    }

    int root = postorder[postE - 1];

    // inorder 루트의 위치
    // [inS, inRoot), [inRoot+1, inE) 두개로 쪼개짐
    // left size = inRoot - inS
    // right size = inE - inRoot - 1
    auto inRootIter = find(inorder.begin(), inorder.end(), root);
    int inRoot = distance(inorder.begin(), inRootIter);

    cout << root << " ";
    // x - postS == inRoot - inS
    preorder(inS, inRoot, postS, postS + inRoot - inS);
    // postE - 1 - x == inE - inRoot - 1
    preorder(inRoot+1, inE, postE - inE + inRoot, postE-1);
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;

    inorder = vector<int>(n);
    postorder = vector<int>(n);

    for (int i=0; i<n; ++i)
        cin >> inorder[i];

    for (int i=0; i<n; ++i)
        cin >> postorder[i];

    preorder(0, n, 0, n);
    cout << endl;
    
    return 0;
}
