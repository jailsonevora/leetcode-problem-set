#include<iostream>
#include<vector>
#include "Include\TreeNode.h"

using namespace std;

class BuildTreeFromPreOrderArray {

    private:
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2);

    protected:    

    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};