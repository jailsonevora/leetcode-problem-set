/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
#include<Util/Include/BuildTreeFromPreOrderArray.h>

using namespace std;

class Solution {
    void kth(TreeNode* root, int& k, int& n, int& ans){

        if(!root)
            return;
        
        kth(root->left,k,n,ans);

        if (k == ++n){
            ans = root->val;
            return;    
        }
        
        kth(root->right,k,n,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, n = 0;
        kth(root,k,n,ans);
        return ans;
    }
};
// @lc code=end
int main(){

    vector<int> inOrder = {1,2,3,4},
                preOrder = {3,1,2,4};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);

    cout << sl.kthSmallest(root,1);
}
