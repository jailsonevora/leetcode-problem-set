#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root)
            return (new TreeNode(val));
                       
        if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};
