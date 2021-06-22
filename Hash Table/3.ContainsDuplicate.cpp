#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for (int it : nums)
        {
            if(duplicate.count(it))
                return true;
            duplicate.insert(it);
        }
        return false;        
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n = {2,4,3,2};

    Solution s;
    s.containsDuplicate(n); 
}