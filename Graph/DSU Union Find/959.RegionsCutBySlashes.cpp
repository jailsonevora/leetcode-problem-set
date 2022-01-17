#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "Util\Include\Graph.h"

using namespace std;

// Union find without path compression
class Solution {

    int count, n;
   vector<int> f;

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        
        n = grid.size();
        count = n * n * 4;
        
        for (int i = 0; i < n * n * 4; ++i)
            f.push_back(i);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));

                if (grid[i][j] != '/') {
                    uni(g(i , j, 0), g(i , j,  1));
                    uni(g(i , j, 2), g(i , j,  3));
                }
                if (grid[i][j] != '\\') {
                    uni(g(i , j, 0), g(i , j,  3));
                    uni(g(i , j, 2), g(i , j,  1));
                }
            }
        }
        return count;        
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

    vector<string> edge = { 
        {" /"},{"/ "}
    };
    
    Solution sl;
    std::cout << sl.regionsBySlashes(edge);
}