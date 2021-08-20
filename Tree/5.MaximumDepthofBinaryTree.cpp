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
        
        // Bottom-Up aproach recrusively
        if(!root)
            return 0;        
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return std::max(left,right)+1;
    }

    int BFS_levelOrder(TreeNode* root) {
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
};