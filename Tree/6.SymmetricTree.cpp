#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

 class Solution {
    bool DFS_Recursive_PreOrderTraversal(TreeNode* rootL, TreeNode* rootR){

        if (!rootL && !rootR)
            return true;
        
        if (!rootL || !rootR)
            return false;

        return ( 
                rootL->val == rootR->val 
                && DFS_Recursive_PreOrderTraversal(rootL->left,rootR->right) 
                && DFS_Recursive_PreOrderTraversal(rootL->right,rootR->left) 
            );
    }
public:
    bool isSymmetric(TreeNode* root) {
        return DFS_Recursive_PreOrderTraversal(root, root);
    }
};