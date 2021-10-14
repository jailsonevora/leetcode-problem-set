#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\TreeNode.h"

using namespace std;

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