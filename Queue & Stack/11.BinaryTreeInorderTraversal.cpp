#include<iostream>
#include<set>
#include<stack>
#include<vector>

using namespace std;

/**
 * 
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void DFS_Recursive(TreeNode* root, vector<int> &ans){
        
        if(root){

            if(root->left)
                DFS_Recursive(root->left, ans);

            ans.push_back(root->val);

            if(root->right)
                DFS_Recursive(root->right, ans);
        }
    }
public:
    //iteratively
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> stck;
        set<TreeNode*> visited;
        vector<int> ans;

        if(!root)
            return ans;

        TreeNode* cur = root;
        while (!stck.empty() || cur)
        {
            while (cur)
            {
                if(!visited.count(cur)){
                    visited.insert(cur);
                    stck.push(cur);
                    cur = cur->left;
                }
            }
            cur = stck.top();
            stck.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }

    //recursive
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        DFS_Recursive(root, ans);        
        return ans;
    }
};