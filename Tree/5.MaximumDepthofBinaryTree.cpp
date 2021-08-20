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
    int maxDepth(TreeNode* root) {
        
        // BFS-LevelOrder aproach Iteratively
        //BFS_Iteratively_levelOrder_maxDepth(root);
        
        // Bottom-Up aproach recrusively
        if(!root)
            return 0;        
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return std::max(left,right)+1;
    }

    // BFS-LevelOrder aproach Iteratively
    int BFS_Iteratively_levelOrder_maxDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int ans;

        if(!root)
            return 0;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {        
                TreeNode* curr = queue.front();
                queue.pop();              
                
                if (curr->left)
                    queue.push(curr->left);
                
                if (curr->right)
                    queue.push(curr->right);
            }
            ans++;
        }
        return ans;
    }

    void DFS_Iteratively_PostOrderTraversal_maxDepth(TreeNode* root, vector<int>&ans){
        
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
};