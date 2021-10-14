#include<iostream>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return 1;
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
    // vector<int> preOrder1 = {1,2};
    // //         1
    // //     2             
    // vector<int> inOrder1 = {2,1};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1,inOrder1);

    Solution sl;
    cout << sl.diameterOfBinaryTree(root);
}

