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

        if(root->left)
            DFS_Recursive(root, ans);

        ans.push_back(root->val);

        if(root->right)
            DFS_Recursive(root, ans);

    }

    // void DFS_Iteratively(TreeNode* root){

    //     stack<TreeNode*> stck;
    //     set<TreeNode*> visited;
    //     vector<int> ans;

    //     stck.push(root);

    //     while (!stck.empty())
    //     {
    //         TreeNode* cur = stck.top();
    //         stck.pop();
            
    //         for (TreeNode* next: cur->left)
    //         {
    //             if(!visited.count(next)){
    //                 visited.insert(next);
    //                 stck.push(next);
    //             }
    //         }
    //     }
    //     return false;
    // }
public:
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        DFS_Recursive(root, ans);        
        return ans;
    }
};