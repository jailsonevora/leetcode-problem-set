/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<Util\Include\BuildTreeFromPreOrderArray.h>

using namespace std;

class Solution {

    int maxDeph(TreeNode* root){

        if(!root)
            return 0;
        int left = 1 + maxDeph(root->left);
        int right = 1 + maxDeph(root->right);

        return max(left,right);
    }

    void dfs(TreeNode* root, int maxdeph, int& ans){

        if(!root)
            return;

        if(!root->left && !root->right && maxdeph == 1)
            ans += root->val;

        dfs(root->left,maxdeph-1,ans);
        dfs(root->right,maxdeph-1,ans);
    }

    void bfs(TreeNode* root, int maxdeph, int& ans){

        queue<TreeNode*> queue;

        queue.push(root);

        while (!queue.empty())
        {
            for (int i = queue.size(); i > 0; i--)
            {
                TreeNode* temp = queue.front();
                queue.pop();

                if(temp->left)
                    queue.push(temp->left);

                if(temp->right)
                    queue.push(temp->right);

                if(maxdeph == 1)
                    ans += temp->val;
            }
            maxdeph--;
        }        
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        
        int ans = 0, maxdeph = maxDeph(root);
        //dfs(root,maxdeph,ans);
        bfs(root,maxdeph,ans);
        return ans;
    }
};
// @lc code=end
int main(){
    vector<int> inOrder = {7,4,2,5,1,3,6,8},
                preOrder = {1,2,4,7,5,3,6,8};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);
    
    cout << sl.deepestLeavesSum(root);
}
