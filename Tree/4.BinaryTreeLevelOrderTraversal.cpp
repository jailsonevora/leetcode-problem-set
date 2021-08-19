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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> ans;

        if(!root)
            return vector<vector<int>>{};

        queue.push(root);
        ans.push_back({root->val});

        while (!queue.empty())
        {
            vector<int> tmp;
            while (!queue.empty())
            {        
                TreeNode* curr = queue.front();
                queue.pop();
                if (curr->left){
                    queue.push(curr->left);
                    tmp.push_back(curr->left->val);
                }
                
                if (curr->right){
                    queue.push(curr->right);
                    tmp.push_back(curr->right->val);
                }
            }
            if(!tmp.empty())
                    ans.push_back(tmp);
        }
        return ans;
    }
};

[1,2,3,4,null,null,5]

1
2,3,
4
