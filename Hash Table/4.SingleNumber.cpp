#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumberN_SET(vector<int>& nums) {
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

    int singleNumberN_MAP(vector<int>& nums) {
        unordered_map<int, int> single;
        for (int it : nums)
            single[it] = single[it]+1;

        for (int it : nums)
            if(single[it] == 1)
                return it;
        return 0;
    }

    int singleNumberBitWise(vector<int>& nums) {
        int a = 0;
        for (int it : nums)
            a ^= it;
        return a;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n = {4,1,2,1,2};

    Solution s;
    cout << s.singleNumberN_SET(n);
}