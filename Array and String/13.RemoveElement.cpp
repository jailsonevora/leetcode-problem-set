#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }

    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[k - 1];
                // reduce array size by one
                k--;
            } else {
                i++;
            }
        }
        return k;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    // int val = 3;
    // vector<int> v = {3,2,2,3};
    int val = 2; 
    vector<int> v = {0,1,2,2,3,0,4,2};

   cout << sl.removeElement(v,val) << "\n";
}