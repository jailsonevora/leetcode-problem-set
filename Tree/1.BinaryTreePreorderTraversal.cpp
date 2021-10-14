#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"


using namespace std;


 class Solution {
    void DFS_Recursive_PreOrderTraversal(TreeNode* root, vector<int>&ans){

        if (!root)
            return;

        ans.push_back(root->val);

        if (root->left)
            DFS_Recursive_PreOrderTraversal(root->left, ans);

        if (root->right)
            DFS_Recursive_PreOrderTraversal(root->right, ans);

    }

    void DFS_Iteratively_PreOrderTraversal(TreeNode* root, vector<int>&ans){
        
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode* curr = stk.top();
            ans.push_back(curr->val);
            stk.pop();            
                  
            if(curr->left){
                stk.push(curr->left);
            }

            if(curr->right){
                stk.push(curr->right);
            } 
               
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> ans;
        
        if(!root)
            return ans;    
        //DFS_Recursive_PreOrderTraversal(root, ans);
        DFS_Iteratively_PreOrderTraversal(root, ans);
        return ans;
    }
};


