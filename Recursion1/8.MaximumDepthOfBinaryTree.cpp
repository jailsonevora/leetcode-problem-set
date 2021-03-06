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
    int dfs_recursion_tail1(TreeNode* root, int n = 1){
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return n;
        else 
            return std::max(dfs_recursion_tail1(root->left, n+1), dfs_recursion_tail1(root->right, n+1));
        n = 1;
        return n; 
    }
    // 2 - tail recursion too
    int dfs_recursion_tail2(TreeNode* root, int n) {
        if (!root) 
            return n;
        n++;
        n = max(dfs_recursion_tail2(root->left, n), dfs_recursion_tail2(root->right, n));
        return n;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs_recursion_tail1(root, 1);
    }
    int maxDepth(TreeNode* root) {
        return dfs_recursion_tail2(root, 0);
    }
};