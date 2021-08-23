#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

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
    bool DFS_Recursive_PreOrderTraversal(TreeNode* root){

        if (!root)
            return false;

        if(root->left->val != root->right->val)
            return false;

        if (root->left)
            DFS_Recursive_PreOrderTraversal(root->left);

        if (root->right)
            DFS_Recursive_PreOrderTraversal(root->right);

    }
public:
    bool isSymmetric(TreeNode* root) {
        
    }
};