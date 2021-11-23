#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        // initialize leads
        vector<int> parent, rank(n,0);

        // instantiate the parents
        for(int i = 0; i < n; ++i)
            parent[i] = i;

        

        
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