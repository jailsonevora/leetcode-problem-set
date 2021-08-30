#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    // vector<int> mergeHalves(vector<int>& nums, int i, vector<int>& tmp, int j){
    //     if(!nums.size())
    //         return tmp;
    //     if(!tmp.size())
    //         return nums;

    //     if(nums[i] >= tmp[j])
    //         tmp[j+1] = mergeHalves(nums, i, tmp, j + 1);
    //     else
    //     {
    //         nums[i+1]=mergeHalves(nums,i + 1, tmp, i);
    //         tmp=nums;
    //     }
    //     return tmp;
    // }
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