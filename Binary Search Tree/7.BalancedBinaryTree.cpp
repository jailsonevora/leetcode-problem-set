#include<iostream>
#include<queue>
#include<map>
#include "Util\Include\TreeNode.h"

using namespace std;

class Solution {
    bool ans = true;
    int height(TreeNode*root){
        
        if(!root)
            return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        ans = ans & abs(l-r) < 2;
        
        return max(l,r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};