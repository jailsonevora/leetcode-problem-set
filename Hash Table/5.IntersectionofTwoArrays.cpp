#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersection, tempSetResult;
        vector<int> temp;

        for (int it : nums1)
            intersection.insert(it);

        for (int it2 : nums2)
        {
            if(intersection.count(it2))
                tempSetResult.insert(it2);
        }

        for (int tp : tempSetResult)
        {
            temp.push_back(tp);
        }
        return temp;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n1 = {4,9,5};
    vector<int> n2 = {9,4,9,8,4};

    Solution s;
    s.intersection(n1, n2); 
}