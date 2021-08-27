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

// both dfs algorithm
class Solution {
    // 1 - Bottom-Up aproach recrusively tail recursion
    int help(TreeNode* root, int n = 0){
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return n;
        else 
            return std::max(help(root->left, n+1), help(root->right, n+1));
        n = 1;
        return n; 
    }
    // 2 - tail recursion too
    int dfs(TreeNode* root, int n) {
        if (!root) 
            return n;
        n++;
        n = max(dfs(root->left, n), dfs(root->right, n));
        return n;
    }
public:
    int maxDepth(TreeNode* root) {
        return help(root, 1);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};