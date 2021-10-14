#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    // tail recursion
    bool dfs(TreeNode* root, int val){
        
        if(!root)
            return true;

        if(val != root->val)
            return false;

        return dfs(root->left, val) && dfs(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
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
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(1);
    //root->right->left = new TreeNode(0);

    Solution sl;
    cout << sl.isUnivalTree(root);
}