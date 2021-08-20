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
            return;        
        
        if(!root->left && !root->right)
            ans = max_depth(root, depth);
        max_depth(root->left, ++depth);
        max_depth(root->right, ++depth);
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        max_depth(root, ans);
    }
};