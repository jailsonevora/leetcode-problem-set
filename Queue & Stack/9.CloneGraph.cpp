#include<iostream>
#include<set>
#include<vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    bool DFS(Node* source, Node* destination, set<Node*> visited){
        if(visited.count(source))
            return false;
        
        visited.insert(source);

        if(source == destination)
            return true;

        for (Node* child: source->neighbors)
            if(DFS(child, destination, visited))
                return true;
        
        return false;
    }
public:
    Node* cloneGraph(Node* node) {
        
    }
};