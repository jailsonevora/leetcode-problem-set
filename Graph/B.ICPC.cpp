#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// find path compression
int _find(int v, vector<int>& parent){

    if(v == parent[v])
        return v;
    return parent[v] = _find(parent[v], parent); // path compression
}

// union by rank
void _union(int from, int to, vector<int>& parent, vector<int>& rank){
    
    if(rank[to] < rank[from])
        parent[to] = from;
    else if(rank[from] < rank[to])
        parent[from] = to;
    else
    {
        parent[to] = from;
        rank[from]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n,m;
    vector<int> event(n+1);
    //vector<int> graph[n+1];
    vector<int,pair<int,int>> graph;
 
    cin>>n;
    cin>>m;
    
    for(int i=1; i<=n; i++){
        int a, b, c;
	    cin >> a >> b >> c;
        graph[i] = a;
        graph[i].push_back({b,c});
    }
 
    // initialize leads
    vector<int> parent(n, 0);
    vector<int> rank(n, 0);

    // intantiate the rankings and parents
    for (int i = 0; i < n; i++)
        parent[i] = i, 
            rank[i] = 0;

    for(auto node: graph){
        if(node[0] == 1){
            int absPFrom = _find(node[0].first, parent);
            int absPTo = _find(node[0].second, parent);

            _union(absPFrom, absPTo, parent, rank);

        }
        else{
            int absPFrom = _find(node.first, parent);
            int absPTo = _find(node.second, parent);
            
            if(absPFrom == absPTo)
                cout << "1";
            else
                cout << "0";
        }
    }    
}