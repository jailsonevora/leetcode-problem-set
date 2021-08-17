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

        unordered_set<int> seen;
        stack<int> stk;
        stk.push(root->val);

        while (!stk.empty())
        {
            int k = stk.top();
            stk.pop();
            ans.push_back(k);

            if(root->left && !seen.count(root->val) || root->right && !seen.count(root->val))
                stk.push(root->val), seen.insert(root->val);           
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


