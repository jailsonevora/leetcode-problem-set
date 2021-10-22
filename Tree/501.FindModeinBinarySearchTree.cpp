#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {3,5,6,2,7,4,1,9,8};
    vector<int> inOrder1 = {6,5,7,2,4,3,9,1,8};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    vector<int> preOrder2 = {3,5,6,7,1,4,2,9,8};
    vector<int> inOrder2 = {6,5,7,3,4,1,9,2,8};

    TreeNode* root2 = bl.buildTree(preOrder2, inOrder2);

    Solution sl;
    cout << sl.leafSimilar(root1, root2);
}