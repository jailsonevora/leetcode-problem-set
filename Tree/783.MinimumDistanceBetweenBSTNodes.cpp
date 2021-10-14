#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    int dfs(TreeNode* root, int& min, int& diff){

        if(root->left)
            dfs(root->left, min, diff); 

        if(diff >= 0)
            min = std::min(min, root->val - diff);

        diff = root->val;

        if(root->right)
            dfs(root->right, min, diff);

        return min;
    }
public:
    int minDiffInBST(TreeNode* root) {
        int min = INT_MAX, diff = -1;
        return dfs(root, min, diff);
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {4,2,1,3,6};
    //         4
    //     2       6
    // 1      3          
    vector<int> inOrder1 = {1,2,3,4,6};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.minDiffInBST(root);
}