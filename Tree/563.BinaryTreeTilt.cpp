#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    int _dfs(TreeNode* root, int& val){
        
        if(!root)
            return 0;
            
        int left = _dfs(root->left, val);
        int right = _dfs(root->right, val);

        val += abs(left - right);

        return root->val + left + right;
    }
public:
    int findTilt(TreeNode* root) {

        int val = 0;
        _dfs(root, val);
        return val;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,3};
    //         1
    //     2       3     
    vector<int> inOrder1 = {2,1,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.findTilt(root);
}