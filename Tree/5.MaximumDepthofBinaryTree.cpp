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
    int sum(TreeNode* root, int& ans) {
        if(!root)
            return;
        
        
        if(!root->left || !root->right)

    }
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        sum(root, ans);
    }
};