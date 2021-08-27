#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>
#include<string>
#include<array>
#include <string.h>

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
    int help(TreeNode* root, int n = 0){
        // Bottom-Up aproach recrusively tail recursion
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return n;
        else 
            return std::max(help(root->left, n+1), help(root->right, n+1));
        n = 1;
        return n; 
    }
    int dfs(TreeNode* root, int acc) {
        if (!root) return acc;
        acc++;
        acc = max(dfs(root->left, acc), dfs(root->right, acc));
        return acc;
    }
public:
    int maxDepth(TreeNode* root) {
        return help(root, 0);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};