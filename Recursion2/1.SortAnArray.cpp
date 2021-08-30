#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void mergeHalves(vector<int>& nums,vector<int>& tmp, vector<int>& tmp2){
        int left = 0;
        int right = 0;

        while (left < tmp.size() && right < tmp2.size())
        {
            if(tmp[left] <= tmp2[right]){
                nums.push_back(tmp[left]);
                left++;
            }else{
                nums.push_back(tmp2[right]);
                right++;
            }
        }

        while(left < tmp.size())
        {
            nums.push_back(tmp[left]);
            left++;
        }

        while(right < tmp2.size())
        {
            nums.push_back(tmp2[right]);
            right++;
        }
    } 

    void mergesort(vector<int>& nums){
        
        if(nums.size() < 2)
            return;

        vector<int> sub1, sub2;
        int middle = nums.size() / 2;

        for (int i = 0; i < middle; i++)
            sub1.push_back(nums[i]);

        for (int i = middle; i < nums.size(); i++)
            sub2.push_back(nums[i]);

        mergesort(sub1);
        mergesort(sub2);
        nums.clear();
        mergeHalves(nums, sub1, sub2);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums);
        return nums;   
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    Solution sl;
    sl.sortArray(nums);
}