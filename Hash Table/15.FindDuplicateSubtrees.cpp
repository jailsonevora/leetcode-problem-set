#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 }

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    TreeNode root;
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);

    root.left->left = new TreeNode(4);
    root.right->left = new TreeNode(2);
    root.right->right = new TreeNode(4);
    root.right->left->left = new TreeNode(4);
    


    Solution sl;
    sl.findDuplicateSubtrees(root);
}