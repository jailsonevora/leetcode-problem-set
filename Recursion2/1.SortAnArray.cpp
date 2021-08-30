#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void mergeHalves(vector<int>& nums,vector<int>& tmp, int leftStart, int rightEnd){

    }
    void mergesort(vector<int>& nums,vector<int>& tmp, int leftStart, int rightEnd){
        if(leftStart >= rightEnd)
            return;

        int middle = (leftStart + rightEnd) / 2;
        mergesort(nums, tmp, leftStart, middle);
        mergesort(nums, tmp, middle + 1, rightEnd);
        mergeHalves(nums, tmp, leftStart, rightEnd);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp;
        mergesort(nums, tmp, 0, nums.size() -1);
    }
};