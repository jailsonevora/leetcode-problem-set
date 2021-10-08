#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// using union find by ranking with path compression
class Solution {

    // find with path compression
    int _find(int v, vector<int>& parent){

    }

    // union by rank
    void _union(){

    }



public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        

        // adjacent list
        vector<string> graph[26];

        // undirected graph
        for(auto& edge: equations)
            graph[edge[0]].push_



    }
};

int main(){

    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    // adjacency matrix
    vector<vector<string>> equations = { 
        {"a","b"},
        {"b","c"}
    };

    // represent the equation Ai / Bi = values[i]
    vector<double> values = {
        2.0, 3.0
    };

    vector<vector<string>> queries = {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };

    Solution sl;

    for(auto q: sl.calcEquation(equations, values, queries))
        cout << q << "\n";

}