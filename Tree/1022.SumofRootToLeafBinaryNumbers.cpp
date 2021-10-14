#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
    // solution 1 top down solution
    int ans = 0;
    void preorderTraversal(TreeNode* root, int val){
        
        if(!root)
            return;

        val = (2 * val) + root->val;

        if(!root->left && !root->right)
            ans += val;

        preorderTraversal(root->left, val);
        preorderTraversal(root->right, val);
    }

    // solution 2 tail recursion  
    int preorderTraversal2(TreeNode* root, int val = 0) {
        if (!root) 
            return 0;
        val = (val * 2 + root->val);
        return 
            !root->left && !root->right 
            ? val 
            : preorderTraversal2(root->left, val) + preorderTraversal2(root->right, val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return preorderTraversal2(root, 0);
        //return ans;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    // vector<int> preOrder = {1,0,0,1,1,0,1};
    // vector<int> inOrder = {0,1,0,1,0,1,1};

    // BuildTreeFromPreOrderArray bl;
    // TreeNode* root = bl.buildTree(preOrder, inOrder);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(1);
    root->right->left = new TreeNode(0);

    Solution sl;
    cout << sl.sumRootToLeaf(root);
}