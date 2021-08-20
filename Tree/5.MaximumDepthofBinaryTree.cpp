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
    int max_depth(TreeNode* root, int& depth) {
        if(!root)
            return 0;        
        
        if(!root->left && !root->right)
            return max_depth(root, depth);
        max_depth(root->left, ++depth);
        max_depth(root->right, ++depth);
    }
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int ans = max_depth(root, depth);
        return ans;
    }
};