#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = digits[0];
        for (int i = 1; i < digits.size(); i++)
            num += (num*10) + digits[i];
         
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    vector<int> nums = {1,2,3};

    sl.plusOne(nums);
}
