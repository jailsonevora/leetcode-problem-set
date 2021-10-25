#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    void _dfs(TreeNode* root, int prev, int cur, int max){

        if(!root)
            return;

        if(root->left)
            _dfs(root->left);

        if(prev == root->val) 
            cur++;
        else 
            cur = 1;
            
        if(cur == max) {
            modes.push_back(root->val);
        }
        if(cur > max) {
            modes.clear();
            modes.push_back(root->val);
            max=cur;
        }

        prev=root->val;

        if(root->right)
            _dfs(root->right);

    }
public:
    vector<int> findMode(TreeNode* root) {

        int prev=INT_MIN, cur, max=INT_MIN;

        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,2};
    vector<int> inOrder1 = {1,2,2};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    // vector<int> preOrder1 = {0};
    // vector<int> inOrder1 = {0};

    // TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    for(auto it: sl.findMode(root))
        cout << it << endl;
}