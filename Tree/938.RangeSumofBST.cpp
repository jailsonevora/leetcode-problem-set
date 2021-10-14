#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
    //iteratively
    void dfs_inorder(TreeNode* root, int low, int high, int& ans){
        
        stack<TreeNode*> stk;
        
        if(!root)
            return;
        
        stk.push(root);
        
        while(!stk.empty()){
            
            TreeNode* tmp = stk.top();
            stk.pop();
            
            if(low <= tmp->val && tmp->val <= high)
                ans += tmp->val;
            
            if(tmp->left)
                stk.push(tmp->left);
            
            if(tmp->right)
                stk.push(tmp->right);                
        }
    }
    
    // recursive
    void dfs_inorder(TreeNode* root, int low, int high, int& ans){
        
        if(!root)
            return;
        
        if(low <= root->val && root->val <= high)
            ans += root->val;
        
        dfs_inorder(root->left, low, high, ans);
        dfs_inorder(root->right, low, high, ans);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        dfs_inorder(root, low, high, ans);
        return ans;        
    }
};