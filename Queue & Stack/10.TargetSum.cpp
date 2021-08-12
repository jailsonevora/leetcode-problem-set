#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int head = 0, tail = nums.size()-1;
        for (; head < tail; )
        {   
            int sum = nums[head]+nums[tail];      
            if (sum > target)
                tail--;
            else if (sum < target)
                head++;
            else
                return vector<int>{head+1, tail+1}.size();
            
        }
        return vector<int>{head, tail}.size();
    }
};