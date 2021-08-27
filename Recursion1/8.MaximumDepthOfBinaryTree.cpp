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
        // Bottom-Up aproach recrusively
        if(!root)
            return 0;
        else if (!root->left && !root->right)
            return n;
        else 
            return std::max(help(root->left, n+1), help(root->right, n+1));
        n = 1;
        return n; 
    }
public:
    int maxDepth(TreeNode* root) {
        return help(root, 0);
    }
};