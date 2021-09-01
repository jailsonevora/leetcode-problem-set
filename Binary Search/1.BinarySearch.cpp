#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int head = 0, tail = nums.size() - 1;

        while(head <= tail)
        {
            int middle = head + (tail - head) / 2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target)
                head = middle + 1;
            else
                tail = middle - 1;
        }       
        return -1;        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> v = {-1,0,3,5,9,12};

    Solution sl;
    sl.search(v,9);
}