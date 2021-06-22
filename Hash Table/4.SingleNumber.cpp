#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> single;
        for (int it : nums)
        {   
            if(single.count(it))
                single.erase(it);
            else
                single.insert(it);
        }
        return *single.begin();
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n = {4,1,2,1,2};

    Solution s;
    cout << s.singleNumber(n);
}