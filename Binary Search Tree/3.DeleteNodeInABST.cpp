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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (!root) return root; //only run in case we are not able to find node
        
        if (root->val == key){
            if(!root->left)
                return root->right;    //if only right child exist
            if(!root->right) 
                return root->left;     //if only left child exist
            if(root->right && root->left){        //if both child exist then find min from right
                TreeNode *temp = root->right;
                while(temp->left) 
                    temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right,root->val);                
            }
        }
        else{
            if (root->val > key)
                root->left = deleteNode(root->left,key);
            else
                root->right = deleteNode(root->right,key);
        }
        return root;
    }
};