/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
#include<Util\Include\BuildTreeFromPreOrderArray.h>

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
    }
};
// @lc code=end
int main(){
    vector<int> inOrder = {1,3,2},
                preOrder = {1,2,3};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);
    
    sl.deepestLeavesSum(root);
}
