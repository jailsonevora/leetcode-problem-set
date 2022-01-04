/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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

#include<algorithm>
#include<iostream>
#include<vector>
#include<Util\Include\BuildTreeFromPreOrderArray.h>

using namespace std;

class Solution {
    int dfs(TreeNode* root){

        if(!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        return min(left,right);

    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root);
    }
};
// @lc code=end
int main(){

    // vector<int> preOrder1 = {2,2,5,5,7};
    // vector<int> inOrder1 = {2,2,5,5,7};
    // vector<int> preOrder1 = {2,2,2};
    // vector<int> inOrder1 = {2,2,2};

    vector<int> preOrder1 = {3,5,6,2,7,4,1,9,8};
    vector<int> inOrder1 = {6,5,7,2,4,3,9,1,8};


    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);


    Solution sl;
    cout << sl.findSecondMinimumValue(root);
}
