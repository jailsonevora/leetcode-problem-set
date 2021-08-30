#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void mergesort(vector<int>& nums,vector<int>& tmp, int leftStart, int rightEnd){
        if(leftStart >= right)
            return;

        int middle = (leftStart + rightEnd) / 2;
        mergesort(nums, tmp, leftStart, middle);
        mergesort(nums, tmp, middle + 1, rightEnd);
        mergeHalves(nums, tmp, leftStart, rightEnd);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(vector<int>& nums,vector<int>& tmp, int leftStart, int rightEnd);
    }
};