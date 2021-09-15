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
    void dfs(TreeNode* root, vector<int>& leaves){
        if(!root)
            return;
        
        if(!root->left && !root->right)
            leaves.push_back(root->val);
        
        dfs(root->left, leaves); 
        dfs(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> v1, v2;

        dfs(root1, v1);
        dfs(root2, v2);

        return v1 == v2;              
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {3,5,6,2,7,4,1,9,8};
    vector<int> inOrder1 = {6,5,7,2,4,3,9,1,8};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    vector<int> preOrder2 = {3,5,6,7,1,4,2,9,8};
    vector<int> inOrder2 = {6,5,7,3,4,1,9,2,8};

    TreeNode* root2 = bl.buildTree(preOrder2, inOrder2);

    Solution sl;
    cout << sl.leafSimilar(root1, root2);
}