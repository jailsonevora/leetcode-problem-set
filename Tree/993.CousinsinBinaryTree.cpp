#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

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