#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include "Include\BuildTreeFromPreOrderArray.h"

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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    int x = 4, y = 3;
    vector<int> preOrder1 = {1,2,4,5,3};
    //         1
    //     2       3
    //  4     5          
    vector<int> inOrder1 = {4,2,5,1,3};

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
    cout << sl.diameterOfBinaryTree(root);
}

