#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
    int maxDepth(TreeNode* root) {
        
        // BFS-LevelOrder aproach Iteratively
        //BFS_Iteratively_levelOrder_maxDepth(root);
        
        // Bottom-Up aproach recrusively
        if(!root)
            return 0;        
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return std::max(left,right)+1;
    }

    // BFS-LevelOrder aproach Iteratively
    int BFS_Iteratively_levelOrder_maxDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        int ans = 0;

        if(!root)
            return 0;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {        
                TreeNode* curr = queue.front();
                queue.pop();              
                
                if (curr->left)
                    queue.push(curr->left);
                
                if (curr->right)
                    queue.push(curr->right);
            }
            ans++;
        }
        return ans;
    }
};