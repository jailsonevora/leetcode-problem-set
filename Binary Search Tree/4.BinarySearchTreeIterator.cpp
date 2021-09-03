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

 class BSTIterator {

    vector<int> nodes;
    int curr = 0;

    void inOrder(TreeNode* root) {
        
        if (!root)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        curr++;
        return nodes[curr-1];
    }
    
    bool hasNext() {
        return curr != nodes.size();
    }
};