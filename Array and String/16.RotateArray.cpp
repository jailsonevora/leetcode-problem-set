#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotatePoint = nums.size() - k % nums.size();
        int head = 0, tail = nums[rotatePoint];

        while (head < tail)
            swap(nums[head],nums[tail]);       
                
        return;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    // int k = 2;
    // vector<int> nums = {-1,-100,3,99};
    int k = 3;
    vector<int> nums = {7,1,2,3,4,5,6};

   sl.rotate(nums,k);
}