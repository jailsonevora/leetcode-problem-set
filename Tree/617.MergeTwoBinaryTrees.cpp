#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
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
    //recursively
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (!root1 || !root2) 
            return root1 ? root1 : root2;

        TreeNode* node = new TreeNode(root1->val + root2->val);

        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        
        return node;
    }

    //iteratively with stack
    TreeNode* dfs_stack(TreeNode* root1, TreeNode* root2){

        if (!root1 && !root2)
            return nullptr;
        if (!root1 || !root2) 
        return root1 ? root1 : root2;

        stack<TreeNode*> st1, st2;

        st1.push(root1);
        st2.push(root2);

        while(!st1.empty()){
            
            TreeNode* tmp1 = st1.top();
            TreeNode* tmp2 = st2.top();
            st1.pop(), st2.pop();

            tmp1->val += tmp2->val;
            
            if(!tmp1->left && tmp2->left)
                tmp1->left = tmp2->left;                
            else if (tmp1->left && tmp2->left){
                st1.push(tmp1->left);
                st2.push(tmp2->left);
            }

            if(!tmp1->right && tmp2->right)
                tmp1->right = tmp2->right;                
            else if (tmp1->right && tmp2->right){
                st1.push(tmp1->right);
                st2.push(tmp2->right);
            }
        }
        return root1;
    }


};