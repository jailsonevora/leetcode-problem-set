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
//#include"Util/Include/BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    // string preOrder(TreeNode* root, string path, vector<string>& ans){

    //     if(!root)
    //         return "";
        
    //     path += to_string(root->val);

    //     if(!root->left && !root->right)
    //         ans.push_back(path);

    //     return preOrder(root->left,path+"->",ans) + preOrder(root->right,path+"->",ans);
    // }
    void preOrder(TreeNode* root, string path, vector<string>& ans){

        if(!root)
            return;

        path += to_string(root->val);

        if(!root->left && !root->right)
            ans.push_back(path);

        preOrder(root->left,path+"->",ans);
        preOrder(root->right,path+"->",ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        preOrder(root,"",ans);
        return ans;        
    }
};
// @lc code=end
int main(){

    vector<int> inOrder = {2,5,1,3},
                preOrder = {1,2,5,3};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);

    sl.binaryTreePaths(root);
}
