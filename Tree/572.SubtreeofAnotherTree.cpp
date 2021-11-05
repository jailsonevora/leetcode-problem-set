#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot)
            return true;
        
        if(!root && !subRoot)
            return ;
        
        return root->val == subRoot->val 
            && isSubtree(root->left, subRoot->left) 
                && isSubtree(root->right, subRoot->right) ? true : false;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //example 1
    vector<int> preOrder1 = {3,4,1,2,5};
    vector<int> inOrder1 = {1,4,2,3,5};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    vector<int> preOrder1 = {4,1,2};
    vector<int> inOrder1 = {1,4,2};
    TreeNode* subRoot = bl.buildTree(preOrder1, inOrder1);


    //example 2
    // vector<int> preOrder1 = {3,4,1,0,2,5};
    // vector<int> inOrder1 = {0,1,2,4,3,5};

    // BuildTreeFromPreOrderArray bl;
    // TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    // vector<int> preOrder1 = {4,1,2};
    // vector<int> inOrder1 = {1,4,2};
    // TreeNode* subRoot = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.isSubtree(root, subRoot);
}