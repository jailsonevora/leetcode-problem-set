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

    // deph first search
    double _dfs(string u, string v, unordered_map<string, vector<pair<string,double>>> graph, unordered_set<string>& visited){

        if(!graph.count(u) || !graph.count(v) ) 
            return -1.0;

        if(u == v) 
            return 1.0;

        visited.insert(u);
        for(auto [vnext, w]: graph[u])
            if(!visited.count(vnext)){
                double rs = _dfs(vnext, v, graph, visited);
                if(rs != -1.0)
                    return rs * w;
            }
        return -1.0      
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        

        // adjacent list
        unordered_map<string, vector<pair<string,double>>> graph;

        // undirected graph
        for(int i=0; i<equations.size(); i++)
            graph[equations[i][0]].push_back({equations[i][1],values[i]}),
            graph[equations[i][1]].push_back({equations[i][0],1.0/values[i]});

        vector<double> ans(queries.size());
        unordered_set<string> visited;

        for (auto q: queries)
            if(!visited.count(q[0]))
                ans.push_back(_dfs(q[0], q[1], graph, visited));       
        return ans;
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