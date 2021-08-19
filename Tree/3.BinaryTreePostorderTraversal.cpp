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
     void DFS_Recursive_PostorderTraversal(TreeNode* root, vector<int>&ans){

        if (!root)
            return;

        if (root->left)
            DFS_Recursive_PostorderTraversal(root->left, ans);

        if (root->right)
            DFS_Recursive_PostorderTraversal(root->right, ans);

        ans.push_back(root->val);

    }
    void DFS_Iteratively_PostOrderTraversal(TreeNode* root, vector<int>&ans){
        
        // stack<TreeNode*> stk;
        // TreeNode* curr = root;

        // while (curr || !stk.empty())
        // {               
        //     while(curr){
        //         stk.push(curr);
        //         curr = curr->left;
        //     }
            
        //     curr = stk.top();
        //     ans.push_back(curr->val);
        //     stk.pop(); 

        //     curr = curr->right;               
        // }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)
            return ans;  
        DFS_Recursive_PostorderTraversal(root, ans);
        return ans;
    }
};