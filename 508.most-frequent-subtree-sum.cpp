/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
#include<bits/stdc++.h>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    
    int dfs(TreeNode* root, vector<int>& ans, unordered_map<int, int> mp){

        if(!root)
            return 0;

        int sum = dfs(root->left, ans) + dfs(root->right, ans);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        vector<int> ans;

        dfs(root, ans);
        return ans;        
    }
};
// @lc code=end
int main(){

    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {};
    vector<int> inOrder1 = {};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    sl.findFrequentTreeSum(root);
}
