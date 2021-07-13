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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
        {         
            auto it = find(numbers.begin(), numbers.end(),target-numbers[i]);  
            if(it != numbers.end())
                ans.push_back(i+1);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

    // int target = 9;
    // vector<int> v = {2,7,11,15};
    // int target = 6; 
    // vector<int> v = {2,3,4};
    int target = -1; 
    vector<int> v = {-1,0};

    for(auto v :sl.twoSum(v,target))
        cout << v << "\n";
}