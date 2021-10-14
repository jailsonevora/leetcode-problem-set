#include<iostream>
#include<queue>
#include<map>
#include "Util\Include\TreeNode.h"

using namespace std;

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