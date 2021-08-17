#include<iostream>
#include<queue>
#include<stack>

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
     void DFS_Recursive(TreeNode* root, vector<int>&ans){
        if (!root)
            return;
        

     }
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        vector<int> ans;     
        DFS_Recursive(root, ans);
        return ans;
    }
};


