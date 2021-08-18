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
    void DFS_Recursive_InorderTraversal(TreeNode* root, vector<int>&ans){

        if (!root)
            return;

        if (root->left)
            DFS_Recursive_InorderTraversal(root->left, ans);

        ans.push_back(root->val);

        if (root->right)
            DFS_Recursive_InorderTraversal(root->right, ans);

    }
    void DFS_Iteratively_InOrderTraversal(TreeNode* root, vector<int>&ans){
        
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty())
        {
                       
            TreeNode* curr = stk.top();
                
            if(curr->left){
                stk.push(curr->left);
            }

            ans.push_back(curr->val);
            stk.pop(); 

            if(curr->right){
                stk.push(curr->right);
            } 
               
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)
            return ans;  
        DFS_Iteratively_InOrderTraversal(root, ans);  
        //DFS_Recursive_InorderTraversal(root, ans);
        return ans;
    }
};