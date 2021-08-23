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
    bool DFS_Recursive_PreOrderTraversal(TreeNode* rootL, TreeNode* rootR){

        if (!rootL || !rootR)
            return false;
        
        if (!rootL && !rootR)
            return true;

        if(rootL->val != rootR->val)
            return false;

        return ( 
            rootL->val == rootR->val 
            && DFS_Recursive_PreOrderTraversal(rootL->left,rootR->right) 
            && DFS_Recursive_PreOrderTraversal(rootL->right,rootR->left) 
            );
    }
public:
    bool isSymmetric(TreeNode* root) {
        return DFS_Recursive_PreOrderTraversal(root, root);
    }
};