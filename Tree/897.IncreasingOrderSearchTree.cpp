#include<iostream>
#include<stack>
#include<queue>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {

        if(!root)
            return root;

        TreeNode* node = new TreeNode(root->val);

        if(root->left)
            node->right = increasingBST(root->left);
        if(root->right)
            node->right = increasingBST(root->right);

        return node;        
    }
};