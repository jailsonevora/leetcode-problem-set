#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Util\Include\Graph.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> outAndIndegree(n, 0);

        for(auto& edge : edges)
            /*outAndIndegree[edge[0]]--,*/ outAndIndegree[edge[1]]++;

        vector<int> ans;
        for (int i = 0; i < n; ++ i)
            if(outAndIndegree[i] == 0)
                ans.push_back(i);
        
        return ans;        
    }
};

int main()
{
    // vector of graph edges as per the above diagram
    // vector<Edge> edges = {
    //     {1, 0}
    // };
    // int N = 2;

    // vector<Edge> edges = {
    //      {1,0},{2,0},{3,1},{3,2}
    // };
    // int N = 4;

    // vector<Edge> edges = {
        
    // };
    // int N = 1;
 
    // build a graph from the given edges
    //Graph graph(edges, N);

    //edges as adjMatrix
    vector<vector<int>> edges = {
        {0,1},{0,2},{2,5},{3,4},{4,2}
    };
    int N = 6;
    
    Solution sl;
    for(auto v: sl.findSmallestSetOfVertices(N, edges))
        cout << v << "\n";
}