#include<iostream>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {

    int dfs(TreeNode* root, int& ans){

        if(!root)
            return 0;

        int left = dfs(root->left, ans);
        int righ = dfs(root->right, ans);
        
        ans = std::max(ans,left+righ);

        return std::max(left,righ)+1;;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int x = 4, y = 3;
    vector<int> preOrder1 = {1,2,4,5,3};
    //         1
    //     2       3
    //  4     5          
    vector<int> inOrder1 = {4,2,5,1,3};

    // int x = 5, y = 4;
    // vector<int> preOrder1 = {1,2};
    // //         1
    // //     2             
    // vector<int> inOrder1 = {2,1};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1,inOrder1);

    Solution sl;
    cout << sl.diameterOfBinaryTree(root);
}

