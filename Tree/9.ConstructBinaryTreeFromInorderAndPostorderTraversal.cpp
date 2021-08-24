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
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if(p1 >= p2 || i1 >= i2)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[p1 - 1]);
        auto it = find(inorder.begin() + i1, inorder.begin() + i2, inorder[i2-1]);
        int diff = it - inorder.begin() - i1;
        
        root->left = buildTree(preorder, p1, p1 + diff, inorder, i1, i1 + diff);
        root->right = buildTree(preorder, p1 + diff + 1, p2, inorder, it + 1,  i2);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size())
            return nullptr;
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

