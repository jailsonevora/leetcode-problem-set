#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    // vector<int> plusOne(vector<int>& digits) {
    //     long long num = 0;
    //     for (int i = 0; i < digits.size(); i++)
    //         num = (num*10) + digits[i];

    //     digits.clear();
    //     num++;
    //     while (num != 0){
    //         digits.push_back(num % 10);
    //         num /= 10;
    //     }
    //     std::reverse(digits.begin(), digits.end());
    //     return digits;         
    // }
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i)
            if(digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        digits.insert(digits.begin(),1);
        return digits;         
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;
    //vector<int> nums = {1,2,3};
     vector<int> nums = {9};


    sl.plusOne(nums);
}
