#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {

    // find with path compression
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

    // a combination of Union Find by rank and path compression  and Indegree/Outdegree
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> node(n,0);

        // keep count of node if come more then 1 time
        // like in any order traversal one node should come only one time
        for(int i=0;i<n;i++){
            
            if(leftChild[i]!=-1){
                node[leftChild[i]]++;
                if(node[leftChild[i]]>1) 
                    return false; 
            }       
            
            if(rightChild[i]!=-1){
                node[rightChild[i]]++;
                if(node[rightChild[i]]>1) 
                    return false;
            }    
        }
        
        // if root node is more then 1
        int root=-1,count=0;
        for(int i=0; i<n; i++){
            if(node[i]==0){ 
                root=i;
                count++;
                if(count>1) 
                    return false;
            }
        }
        
        //if no root found then false
        if(root==-1) return false;

        // initialize leads
        vector<int> parent(n,0), rank(n,0);

        // instantiate the parents
        for(int i = 0; i < n; ++i)
            parent[i] = i;

        // join left child
        for(int i = 0; i < leftChild.size(); ++i){

            if(leftChild[i] == -1)
                continue;

            int absFrom = _find(i, parent);
            int absTo = _find(leftChild[i], parent);

            _union(absFrom, absTo, rank, parent);
        }

        // join right child
        for(int i = 0; i < rightChild.size(); ++i){

            if(rightChild[i] == -1)
                continue;

            int absFrom = _find(i, parent);
            int absTo = _find(rightChild[i], parent);

            _union(absFrom, absTo, rank, parent);
        }

        count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                count++;
                if(count>1) 
                    return false;
            }
        }
        return true;        
    }
};

int main(){

    // ex1
    // int n = 4;
    // vector<int> leftChild = {
    //     1,-1,3,-1
    // },
    // rightChild = {
    //     2,-1,-1,-1
    // };

    // ex2
    int n = 4;
    vector<int> leftChild = {
        1,-1,3,-1
    },
    rightChild = {
        2,3,-1,-1
    };

    // ex3
    // int n = 2;
    // vector<int> leftChild = {
    //     1,0
    // },
    // rightChild = {
    //     -1,-1
    // };

    // ex4
    // int n = 6;
    // vector<int> leftChild = {
    //     1,-1,-1,4,-1,-1
    // },
    // rightChild = {
    //     2,-1,-1,5,-1,-1
    // };

    Solution sl;
    cout << sl.validateBinaryTreeNodes(n, leftChild, rightChild);
}