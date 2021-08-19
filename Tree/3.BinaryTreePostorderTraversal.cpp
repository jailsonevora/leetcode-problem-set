#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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
            }

            if(curr->right){
                stk.push(curr->right);
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