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

}