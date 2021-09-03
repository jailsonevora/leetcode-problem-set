#include<iostream>
#include<queue>
#include<map>

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
    //Binary Search
    TreeNode* binarySearch(vector<int>& nums, int head, int tail){
        
        if (head >= tail) 
            return nullptr;
            
        int mid = (head + tail) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = binarySearch(nums, head, mid);
        node->right = binarySearch(nums, mid+1, tail);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size());
    }  
};