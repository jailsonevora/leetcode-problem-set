#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {

    //top-dowm aproach
    void DFS_Recursive_PreOrderTraversal(TreeNode* root, bool &ans, int targetSum){

        if (!root)
            return;

        if (!root->left && !root->right && targetSum - root->val == 0)
            ans = true;
        
        DFS_Recursive_PreOrderTraversal(root->left, ans, targetSum - root->val);
        DFS_Recursive_PreOrderTraversal(root->right, ans, targetSum - root->val);
    }

public:
    //top-down aproach
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        
        if(!root)
            return ans;
            
        DFS_Recursive_PreOrderTraversal(root, ans, targetSum);

        return ans;
    }

    //botton-up aproach
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) 
            return false;
        
        targetSum -= root->val;
        
        if(!root->left && !root->right)
            return targetSum == 0;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
