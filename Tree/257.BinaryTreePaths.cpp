#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    void dfs_(TreeNode* root, string path, vector<string>& str){
        
        if(!root)
            return;

        if(!root->left && !root->right)
            str.push_back(path + to_string(root->val));

        dfs_(root->left, path + to_string(root->val) + "->", str); 
        dfs_(root->right, path + to_string(root->val) + "->", str);        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> str;
        dfs_(root, "", str);
        return str;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,5,3};
    //         1
    //     2       3
    //       5          
    vector<int> inOrder1 = {5,2,1,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    sl.binaryTreePaths(root);
}