#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    //with map
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> mp;
        int ans=0;
        
        for(auto a: nums1)
            for(auto b:nums2)
                mp[a+b]++;
        for(auto c:nums3)
            for(auto d:nums4)
                ans+=mp[0-c-d];
        return ans;
    }
    // with array
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {        
        
        int mp[1024] = {0}, ans=0;
        
        for(int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
                mp[nums1[i]+nums2[j]]++;
        for(int i = 0; i < nums3.size(); i++)
            for(int j = 0; j < nums4.size(); j++)
                ans+=mp[0-nums3[i]-nums4[j]];
        return ans;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> n1 = {1,2}, n2 = {-2,-1}, n3 = {-1,2}, n4 = {0,2};
 
    Solution s;
    s.fourSumCount(n1,n2,n3,n4);
}