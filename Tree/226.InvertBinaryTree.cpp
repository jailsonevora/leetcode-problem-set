#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (!root)
            return nullptr;

        TreeNode* left = root->left, *right = root->right; 

        root->left = invertTree(right);
        root->right = invertTree(left);

        return root;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder = {4,2,1,3,7,6,9};
    vector<int> inOrder = {1,2,3,4,6,7,9};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder, inOrder);

    Solution sl;
    sl.invertTree(root);
}