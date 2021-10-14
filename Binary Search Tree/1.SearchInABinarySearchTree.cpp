#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return root;

        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);        
    }
}; 