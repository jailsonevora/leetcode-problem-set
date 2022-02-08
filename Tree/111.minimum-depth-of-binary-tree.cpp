/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

class Solution {
public:
    // post order traversal
    int minDepth(TreeNode* root) {

        if(!root)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + (min(left, right) ? min(left, right) : max(left, right));
    }
};
// @lc code=end
int main(){
    vector<int> inOrder = {9,3,15,20,7},
                preOrder = {3,9,20,15,7};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);
    
    sl.minDepth(root);
}

