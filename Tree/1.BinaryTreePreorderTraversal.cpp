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
    void DFS_Recursive(TreeNode* root, vector<int>&ans){
        if (!root)
            return;

        ans.push_back(root->val);

        if (root->left)
            DFS_Recursive(root->left, ans);

        if (root->right)
            DFS_Recursive(root->right, ans);

    }

    void DFS_Iteratively(TreeNode* root, vector<int>&ans){

        unordered_set<TreeNode*> seen;
        stack<int> stk;
        stk.push(root->val);

        while (!stk.empty())
        {
            /* code */
        }
        


    }
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> ans;     
        //DFS_Recursive(root, ans);
        DFS_Iteratively(root, ans);
        return ans;
    }
};


