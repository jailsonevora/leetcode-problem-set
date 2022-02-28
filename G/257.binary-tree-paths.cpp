/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include"Util/Include/BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
    }
};
// @lc code=end
int main(){

    vector<int> inOrder = {1,2,3,4},
                preOrder = {3,1,2,4};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);

    sl.binaryTreePaths(root);
}
