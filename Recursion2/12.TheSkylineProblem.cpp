#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int,int>> edges;
        for(int i=0;i<n;i++){
            //handling edge cases
            //we will sort edges on the basis of x, and we want heigher height to come first for same x and lower height to come first for same ends
            edges.push_back({buildings[i][0],-1*buildings[i][2]});
            edges.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(edges.begin(),edges.end());
        int prev_max = 0;
        vector<vector<int>> ans;
        multiset<int> pq; //remove, max element, insert all are O(logn) and moreover can contain duplicate entries
        pq.insert(0);
        for(int i=0;i<2*n;i++){
            if(edges[i].second < 0){
                pq.insert(-1*edges[i].second);
            }else{
                //if it is endpoint, then its height will now not exist
                pq.erase(pq.find(edges[i].second));
            }
            int curr_max = (*pq.rbegin());
            if(curr_max != prev_max){
                //whenever we get new max height for current starting point , we have to add it in final ans. This is because while making skyline and we were moving horizontaly and suddenly encountered greater height so will be moving towards this point now to make skyline (see how skyline is made)
                //after encountering end, we remove it. We don't add it in final ans if its height is less than prev_max as that means that a building having greater height is still there so this point will not been seen. otherwise this point will be seen, so add it will curr_max as height
                //after encountering end, we remove it and then if height changes, that means its height was prevoisly maximum, so add this point with curr_max as height
                ans.push_back({edges[i].first,curr_max});
                prev_max = curr_max;
            }
        }
        return ans;
    }
};