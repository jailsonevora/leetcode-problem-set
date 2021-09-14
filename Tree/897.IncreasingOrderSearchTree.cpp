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

    TreeNode* increasingBST(TreeNode* root) {
        
        if (!root) 
            return nullptr;

        increasingBST(root->left);
        
        if (!newroot) { 
            newroot = new TreeNode(root->val);
            curr = newroot;
        }
        else {
            curr->right = new TreeNode(root->val);
            curr = curr->right;
        }
        
        increasingBST(root->right);
        
        return newroot;
    }

    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* tmp, *newNode;
        newNode = new TreeNode();
        tmp = newNode;
        inorder(root, newNode);
        return tmp->right;                
    }
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