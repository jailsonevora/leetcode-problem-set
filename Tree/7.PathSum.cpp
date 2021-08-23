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

    //top-dowm aproach
    void DFS_Recursive_PreOrderTraversal(TreeNode* root, bool &ans, int targetSum){

        if (!root)
            return;

        if (!root->left && !root->right && targetSum - root->val == 0)
            ans = true;
        
        DFS_Recursive_PreOrderTraversal(root->left, ans, targetSum - root->val);
        DFS_Recursive_PreOrderTraversal(root->right, ans, targetSum - root->val);
    }

public:
    //top-down aproach
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        
        if(!root)
            return ans;

        DFS_Recursive_PreOrderTraversal(root, ans, targetSum);

        return ans;
    }
};
