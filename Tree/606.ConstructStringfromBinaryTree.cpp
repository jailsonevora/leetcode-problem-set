#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    string tree2str(TreeNode* root) {
        
        if (!root) 
            return "";

        string s = to_string(root->val);
        if (root->left) 
            s += '(' + tree2str(root->left) + ')';
        else if (root->right) 
            s += "()";
        
        if (root->right) 
            s += '(' + tree2str(root->right) + ')';
        return s;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,4,3};
    //         1
    //     2       3
    // 4          
    vector<int> inOrder1 = {4,2,1,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.tree2str(root);
}