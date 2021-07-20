#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next = 1, i = 0;
        while (next < nums.size()){
            if(nums[next] == nums[i]){
                i = next; 
                while (nums[next] == nums[i])
                    ++next;
                nums[i] = nums[next];               
            }             
        }
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    vector<int> v = {1,1,2};
    //vector<int> v = {0,0,1,1,1,2,2,3,3,4};

   cout << sl.removeDuplicates(v) << "\n";
}