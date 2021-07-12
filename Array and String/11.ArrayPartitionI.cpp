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
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0, j = 1; i < nums.size(); i+=2,j+=2)
            sum+=min(nums[i],nums[j]);
        return sum;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    //vector<int> v = {1,4,3,2};
    vector<int> v = {6,2,6,5,1,2};

    cout << sl.arrayPairSum(v);
}