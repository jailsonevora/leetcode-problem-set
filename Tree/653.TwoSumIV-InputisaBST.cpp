#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    // using set
    unordered_set<int> s;
    bool findTarget_Set(TreeNode* root, int k) {
        
        if (!root) 
            return false;
        if (s.count(k - root->val)) 
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

    // dfs recursive
    bool dfs_preOrderTraversal(TreeNode* root, TreeNode* curr, int k){

        if(!curr)
            return false;
        return binarySearch(root, curr, k - curr->val) || dfs_preOrderTraversal(root, curr->left, k) ||
        dfs_preOrderTraversal(root, curr->right, k);      
    }

    // binary search
    bool binarySearch(TreeNode* root, TreeNode *cur, int value){
        if(!root)
            return false;
        return (root->val == value) && (root != cur) 
            || (root->val < value) && binarySearch(root->right, cur, value) 
                || (root->val > value) && binarySearch(root->left, cur, value);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs_preOrderTraversal(root, root, k);        
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