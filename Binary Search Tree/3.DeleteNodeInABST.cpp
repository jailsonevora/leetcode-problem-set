#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\TreeNode.h"

using namespace std;

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