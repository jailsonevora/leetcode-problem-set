#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


// Union find with path compression
class SolutionDSU {

    int _find(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = _find(parent[v]);
    }
    
    void _union(int from, int to, vector<int>& parent) {
        from = _find(from);
        to = _find(to);
        if (from != to)
            parent[to] = from;
    }
public:
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int i, j, province = 0, n = M.size();
        
        // initialize leads for every kid as themselves
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;  
          
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                if(M[i][j])
                    _union(i, j);
        
        for(i = 0; i < n; i++)
            if(i == parent[i])
                province++;
        
        return province;
    }
};

// with DFS
// class SolutionDFS {
//     void _dfs(vector<vector<int>> &grid, int v, vector<int>& visited){
               
//         for (int u = 0; u < grid.size(); u++)
//             if(grid[v][u] == 1 && visited[u] == 0){
//                 visited[u] = 1;
//                 _dfs(grid, u, visited);
//             }
//     }
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {

//         int province = 0;
//         vector<int> visited(isConnected.size(), 0);
        
//         for(int row = 0; row < isConnected.size(); row++)
//             if(visited[row] == 0)
//                 _dfs(isConnected, row, visited), 
//                     province++;
//         return province;        
//     }
// };

int main()
{

    vector<vector<int>> grid = { 
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    // vector<vector<int>> grid = { 
    //     {1,0,0},
    //     {0,1,0},
    //     {0,0,1}
    // };
    
    SolutionDFS sl;
    SolutionDSU sl;
    std::cout << sl.findCircleNum(grid);
}