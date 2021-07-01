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
 };

class Solution {
public:

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){

        unordered_set<string> st, dummy; vector<TreeNode*> result;
        
        if(!root) return result;  
          
        findDuplicateSubtrees(root,st,dummy,result);
        return result;
    }
    string findDuplicateSubtrees(TreeNode* root, unordered_set<string> &st, unordered_set<string> &dummy, vector<TreeNode*> &result){
        
        if (!root) return "";

        string treeStr = "["+ findDuplicateSubtrees(root->left,st,dummy,result) 
                            + to_string(root->val) 
                            + findDuplicateSubtrees(root->right,st,dummy,result) 
                            +"]";
        if(!st.insert(treeStr).second && dummy.insert(treeStr).second)
            result.push_back(root);
        return treeStr;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    TreeNode node(1);
    node.left = new TreeNode(2);
    node.right = new TreeNode(3);

    node.left->left = new TreeNode(4);
    node.right->left = new TreeNode(2);
    node.right->right = new TreeNode(4);
    node.right->left->left = new TreeNode(4);
    
    TreeNode *root = &node;


    Solution sl;
    sl.findDuplicateSubtrees(root);
}