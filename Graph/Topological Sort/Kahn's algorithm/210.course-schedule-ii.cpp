/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Solution {
    vector<int> khanalgorithm(int numCourses, vector<vector<int>>& prerequisites) {
        // Khan algorithm
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
            
            for(auto edge : prerequisites) 
                graph[edge[1]].push_back(edge[0]),
                    indegree[edge[0]]++;
            
            queue<int> queue;
            for(int u = 0; u < numCourses; u++)
                if(indegree[u] == 0)
                    queue.push(u);   

            while(!queue.empty()) {

                int u = queue.front();
                ans.push_back(u);
                queue.pop();
                
                for(auto v : graph[u])
                    if(--indegree[v] == 0)
                        queue.push(v);
            }
            return ans.size() == numCourses ? ans : vector<int>();
    }
public:
    
    // khan algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return khanalgorithm(numCourses,prerequisites); 
    }
};
// @lc code=end
int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};

    Solution sl;
    sl.findOrder(numCourses, prerequisites);
}

