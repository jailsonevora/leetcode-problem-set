#include<iostream>
#include<stack>
#include<queue>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
     
    TreeNode* newroot, *curr;

    void inorder(TreeNode* root, TreeNode*& newNode){
        
        if(!root)
            return;

        inorder(root->left, newNode);

        newNode->right = new TreeNode(root->val);
        newNode = newNode->right;
        
        inorder(root->right, newNode);
    }
public:
    //solution 1 reusing the root
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) 
            return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }

    // solution 2
    // TreeNode* increasingBST(TreeNode* root) {
        
    //     if (!root) 
    //         return nullptr;

    //     increasingBST(root->left);
        
    //     if (!newroot) { 
    //         newroot = new TreeNode(root->val);
    //         curr = newroot;
    //     }
    //     else {
    //         curr->right = new TreeNode(root->val);
    //         curr = curr->right;
    //     }
        
    //     increasingBST(root->right);
        
    //     return newroot;
    // }
    // solution 3
    // TreeNode* increasingBST(TreeNode* root) {

    //     TreeNode* tmp, *newNode;
    //     newNode = new TreeNode();
    //     tmp = newNode;
    //     inorder(root, newNode);
    //     return tmp->right;                
    // }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution sl;
    sl.increasingBST(root);
}