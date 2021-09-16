#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 
class BuildTreeFromPreOrderArray {
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if(p1 > p2)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[p1]);
        int i = i1;
        while (i <= i2) {
            if (inorder[i] == root->val) break;
            i ++;
        }

        int diff = i - i1 - 1;
        p1++;
        
        root->left = buildTree(preorder, p1, p1 + diff, inorder, i1, i1 + diff);
        root->right = buildTree(preorder, p1 + diff + 1, p2, inorder, i + 1,  i2);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size())
            return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
}; 

class Solution {
    void dfs(TreeNode* root, string& str){

        if(!root){
            str.push_back(')');
            return;
        }

        if(!root->left && !root->right)
            str.push_back(')');
        
        str.push_back(root->val);
        str.push_back('(');
        
        dfs(root->left, str);
        dfs(root->right, str);

    }
public:
    string tree2str(TreeNode* root) {

        string str;
        dfs(root, str);        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    // vector<int> preOrder1 = {5,3,2,4,6,7};
    // vector<int> inOrder1 = {2,3,4,5,6,7};

    vector<int> preOrder1 = {2,0,-4,1,3};
//         2
//     0       3
// -4      1    
    vector<int> inOrder1 = {-4,0,1,2,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.findTarget(root, -1);
}