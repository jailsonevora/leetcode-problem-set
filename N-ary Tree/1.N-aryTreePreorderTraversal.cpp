#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    
public:
    vector<int> preorder(Node* root) {

        vector<int> ans;
        preorder(root, ans);
        return ans;
        
    }
};