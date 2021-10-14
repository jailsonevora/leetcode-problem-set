#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
    //pre-order traversal iterativelly
    int _dfs_iterativelly(TreeNode* root, int& sum){

        stack<TreeNode*> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode* tmp = st.top();
            st.pop();

            if(tmp->left && !tmp->left->left && !tmp->left->right)   
                sum += tmp->left->val;

            if(tmp->left)
                st.push(tmp->left);

            if(tmp->right)
                st.push(tmp->right);
        }
        return sum;        
    }
    // in-order traversal recursive
    int _dfs_left(TreeNode* root, int& sum){
        
        if(!root)
            return 0;
            
        _dfs_left(root->left, sum);
        
        if(root->left && !root->left->left && !root->left->right)   
            sum += root->left->val;
        
        _dfs_left(root->right, sum);

        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return _dfs_iterativelly(root, sum);
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {3,9,20,15,7};
    //         4
    //     2       6
    // 1      3          
    vector<int> inOrder1 = {9,3,15,20,7};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.sumOfLeftLeaves(root);
}