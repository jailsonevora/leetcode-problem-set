#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void mergeHalves(vector<int>& nums,vector<int>& tmp, int leftStart, int rightEnd){
        int leftEnd = (rightEnd + leftStart) / 2;
        int rightStart = leftEnd + 1;
        int size = rightStart - leftStart + 1;

        int left = leftStart;
        int right = rightStart;
        int index = leftStart;

        while (left <= leftEnd && right <= rightEnd)
        {
            if(nums[left] <= nums[right]){
                tmp[index] = nums[left];
                left++;
            }else{
                tmp[index] = nums[right];
                right++;
            }
            index++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]){
                tmp[index] = nums[i];
                index++;
            }
        }
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
        return tmp;
    }
};