#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int next = 1, i = 0;
        while (next < nums.size()){
            if(nums[next] != 0){
                nums[i] = nums[next];
                i++;
            }        
            next++;          
        }
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    vector<int> v = {0,1,0,3,12};
    //vector<int> v = {0,0,1,1,1,2,2,3,3,4};

   sl.moveZeroes(v);
}