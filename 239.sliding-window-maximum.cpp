/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    // O(n*k) TLE
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    //     int left = 0, right = k-1;
    //     vector<int> ans;

    //     while (right < nums.size())
    //     {
    //         int curr = left;
    //         priority_queue<int,vector<int>,less<int>> pq;
    //         while (curr <= right)
    //         {
    //             pq.push(nums[curr]);
    //             curr++;
    //         }
    //         ans.push_back(pq.top());
    //         left++, right++;
    //     }
    //     return ans;
    // }

    // O(n*logk) 
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    //     priority_queue<pair<int,int>> pq;
    //     vector<int>ans;
        
    //     int left = 0;
    //     for(left=0; left < k; left++)
    //         pq.push({nums[left],left});

    //     ans.push_back(pq.top().first);
    //     for(int curr=left; curr < nums.size(); curr++){
            
    //         pq.push({nums[curr],curr});
    //         while(pq.top().second <= curr-k) 
    //             pq.pop();

    //         ans.push_back(pq.top().first);
    //     }
    //     return ans;
    // }

    // O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<pair<int,int>>dq;
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){

            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            
            dq.push_back({nums[i],i});
            if(i >= k-1){
                if(dq.front().second==i-k) 
                    dq.pop_front();
                ans.push_back(dq.front().first);
            }
        }
        return ans;
    }
};
// @lc code=end
int main(){

    Solution sl;

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // int k = 3;

    vector<int> nums = {1};
    int k = 1;

    sl.maxSlidingWindow(nums,k);
}
