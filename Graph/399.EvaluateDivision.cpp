#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


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
        vector<string, pair<string,double>> graph[10000];

        // undirected graph
        for(int i=0;i<equations.size();i++)
        {
            string from=equations[i][0];
            string to=equations[i][1];
            graph[from].insert({to,values[i]});
            graph[to].insert({from,1.0/values[i]});
        }



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