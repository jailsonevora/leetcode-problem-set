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

        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {        
                TreeNode* curr = queue.front();
                queue.pop();                
                tmp.push_back(curr->val);
                
                if (curr->left)
                    queue.push(curr->left);
                
                if (curr->right)
                    queue.push(curr->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};