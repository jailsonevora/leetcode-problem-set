#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ptr = 0, ans = 0;
        for(int i = 0; i < nums.size();++i){
            if(nums[i] == 1){
                ptr++;
                ans = max(ans,ptr);
            }
            else
                ptr=0;
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    vector<int> v = {1,1,0,1,1,1};

   cout << sl.findMaxConsecutiveOnes(v) << "\n";
}