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

    vector<int> preOrder1 = {1,2,2};
    vector<int> inOrder1 = {1,2,2};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    vector<int> preOrder2 = {0};
    vector<int> inOrder2 = {0};

    TreeNode* root2 = bl.buildTree(preOrder2, inOrder2);

    Solution sl;
    cout << sl.leafSimilar(root1, root2);
}