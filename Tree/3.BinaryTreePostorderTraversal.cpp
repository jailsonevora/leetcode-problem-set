#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

 class Solution {
     void DFS_Recursive_PostOrderTraversal(TreeNode* root, vector<int>&ans){

        if (!root)
            return;

        if (root->left)
            DFS_Recursive_PostOrderTraversal(root->left, ans);

        if (root->right)
            DFS_Recursive_PostOrderTraversal(root->right, ans);

        ans.push_back(root->val);
    }
    void DFS_Iteratively_PostOrderTraversal(TreeNode* root, vector<int>&ans){
        
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* curr = stk.top();
                        
            if(curr->left){
                stk.push(curr->left);
                curr->left = NULL;
                continue;
            }

            if(curr->right){
                stk.push(curr->right);
                curr->right = NULL;
                continue;
            } 

            ans.push_back(curr->val);
            stk.pop();               
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)
            return ans;  
        DFS_Recursive_PostOrderTraversal(root, ans);
        return ans;
    }
};