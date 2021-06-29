#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> v;

        for (int i = 0; i < nums1.size(); i++)
            v[nums1[i]]++;

        vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
            if(v.count(nums2[i]) && v[nums2[i]] != 0){
                v[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        return result;        
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int v[1024] = {0};
        for(int i = 0; i < nums1.size(); i++)
            v[nums1[i]]++;

        vector<int> result;
        for(int i = 0; i < nums2.size(); i++)
            if(v[nums2[i]] != 0){
                v[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        return result;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    //vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};


    Solution sl;
    sl.intersect(nums1,nums2);
}