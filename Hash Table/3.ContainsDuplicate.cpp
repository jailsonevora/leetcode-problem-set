#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> duplicate;
        for (auto it : nums)
        {
            if(duplicate.count(it) > 0)
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