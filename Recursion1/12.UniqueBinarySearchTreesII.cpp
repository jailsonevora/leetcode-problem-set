#include<iostream>
#include<vector>
#include<map>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
     //with dp using ordered_map
    vector<TreeNode*> help(int start, int end, map<pair<int,int>, vector<TreeNode*>> &dp){
        if(start>end){
            vector<TreeNode*> ans;
            ans.push_back(NULL);
            return ans;
        }
        
        if(dp.count({start,end}))
            return dp[{start,end}];
         
        vector<TreeNode*> ans;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = help(start,i-1,dp);
            vector<TreeNode*> right = help(i+1,end,dp);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        
        dp[{start,end}] = ans;
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {

        map<pair<int,int>,vector<TreeNode*>> dp;
        return help(1,n,dp);
    }
};
