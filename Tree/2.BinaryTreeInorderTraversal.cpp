#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

 class Solution {
    void DFS_Recursive_InOrderTraversal(TreeNode* root, vector<int>&ans){

        if (!root)
            return;

        if (root->left)
            DFS_Recursive_InOrderTraversal(root->left, ans);

        ans.push_back(root->val);

        if (root->right)
            DFS_Recursive_InOrderTraversal(root->right, ans);

    }
    void DFS_Iteratively_InOrderTraversal(TreeNode* root, vector<int>&ans){
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr || !stk.empty())
        {               
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            ans.push_back(curr->val);
            stk.pop(); 

            curr = curr->right;               
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(!root)
            return ans;  
        DFS_Iteratively_InOrderTraversal(root, ans);  
        //DFS_Recursive_InOrderTraversal(root, ans);
        return ans;
    }
};