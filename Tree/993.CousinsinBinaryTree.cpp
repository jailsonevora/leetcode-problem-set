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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void _dfs(TreeNode* root, int x, int depth, int parent, int& depthN, int& parentN){

        if(!root)
            return;

        if(root->val == x){
            depthN = depth;
                parentN = parent;
                    return;
        }
        
        _dfs(root->left, x, depth + 1, root->val, depthN, parentN);
        _dfs(root->right, x, depth + 1, root->val, depthN, parentN);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {

        int xdepth, ydepth, xparent, yparent;


        if(root->val == x || root->val == y) 
            return false;

        _dfs(root, x, 0, 0, xdepth, xparent);
        _dfs(root, y, 0, 0, ydepth, yparent);

        if(xdepth == ydepth && xparent != yparent)
            return true;
        return false;        
    }
};

class Solution {

    int xdepth, ydepth, xparent, yparent;
    void _dfs(TreeNode* root, int x, int y, int depth, int parent){

        if(!root)
            return;

        if(root->val == x){
            xdepth = depth;
                xparent = parent;
                    return;
        }
        
        if(root->val == y){
            ydepth = depth;
                yparent = parent;
                    return;
        }
        
        _dfs(root->left, x, y, depth + 1, root->val);
        _dfs(root->right, x, y, depth + 1, root->val);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {

        if(root->val == x || root->val == y) 
            return false;

        _dfs(root, x, y, 0, 0);

        if(xdepth == ydepth && xparent != yparent)
            return true;
        return false;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int x = 4, y = 3;
    vector<int> preOrder1 = {1,2,4,3};
    //         1
    //     2       3
    // 4                
    vector<int> inOrder1 = {4,2,1,3};

    // int x = 5, y = 4;
    // vector<int> preOrder1 = {1,2,4,3,5};
    // //         1
    // //     2       3
    // //        4         5         
    // vector<int> inOrder1 = {2,4,1,3,5};

    // int x = 2, y = 3;
    // vector<int> preOrder1 = {1,2,4,3};
    // //         1
    // //     2       3
    // //        4               
    // vector<int> inOrder1 = {2,4,1,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.isCousins(root, x, y);
}