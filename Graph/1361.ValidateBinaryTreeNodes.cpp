#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {

    // find path compression
    int _find(int v, vector<int>& parent){

        if(v == parent[v])
            return v;
        return parent[v] = _find(parent[v], parent);
    }

    // union by rank
    void _union(int from, int to, vector<int>& rank, vector<int>& parent){

        if(rank[to] < rank[from])
            parent[to] = from;
        else if(rank[from] < rank[to])
            parent[from] = to;
        else{
            parent[to] = from;
            rank[from]++;
        }
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        // initialize leads
        vector<int> parent, rank(n,0);

        // instantiate the parents
        for(int i = 0; i < n; ++i)
            parent[i] = i;

        //

        

        
    }
};

int main(){

    int n = 4;
    vector<int> leftChild = {
        1,-1,3,-1
    },
    rightChild = {
        2,-1,-1,-1
    };

    // int n = 4;
    // vector<int> leftChild = {
    //     1,-1,3,-1
    // },
    // rightChild = {
    //     2,3,-1,-1
    // };

    // int n = 2;
    // vector<int> leftChild = {
    //     1,0
    // },
    // rightChild = {
    //     -1,-1
    // };

    // int n = 4;
    // vector<int> leftChild = {
    //     1,-1,-1,4,-1,-1
    // },
    // rightChild = {
    //     2,-1,-1,5,-1,-1
    // };

    Solution sl;
    cout << sl.validateBinaryTreeNodes(n, leftChild, rightChild);
}