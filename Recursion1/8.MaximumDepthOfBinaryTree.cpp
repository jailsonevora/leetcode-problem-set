#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>
#include<string>
#include<array>
#include <string.h>

using namespace std;

class Solution {
public:
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
};