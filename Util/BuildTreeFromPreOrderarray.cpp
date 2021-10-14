#include "Util\Include\BuildTreeFromPreOrderArray.h"

TreeNode* BuildTreeFromPreOrderArray::buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
    
    if(p1 > p2)
        return nullptr;
    
    TreeNode *root = new TreeNode(preorder[p1]);
    int i = i1;
    while (i <= i2) {
        if (inorder[i] == root->val) break;
        i ++;
    }

    int diff = i - i1 - 1;
    p1++;
    
    root->left = BuildTreeFromPreOrderArray::buildTree(preorder, p1, p1 + diff, inorder, i1, i1 + diff);
    root->right = BuildTreeFromPreOrderArray::buildTree(preorder, p1 + diff + 1, p2, inorder, i + 1,  i2);
    
    return root;
}

TreeNode* BuildTreeFromPreOrderArray::buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    if(!inorder.size())
        return nullptr;
    return BuildTreeFromPreOrderArray::buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}