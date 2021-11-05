#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {3,4,1,2,5};
    vector<int> inOrder1 = {1,4,2,3,5};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    // vector<int> preOrder1 = {0};
    // vector<int> inOrder1 = {0};

    // TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    for(auto it: sl.findMode(root))
        cout << it << endl;
}