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
    void DFS(Node* source, Node* destination, vector<Node*>& visited){
        
        visited[destination->val] = destination;
        for (Node* child: source->neighbors){
            if(!visited[child->val]){
                Node* newNode = new Node(child->val);
                (destination->neighbors).push_back(newNode);
                DFS(child, newNode, visited);
            }
            else
                (destination->neighbors).push_back(visited[child->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {

        if(!node)
            return NULL;
        
        vector<Node*> visited(1000,NULL);
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        for (Node* child: node->neighbors){
            
            if(!visited[child->val]){
                Node* newNode = new Node(child->val);
                (copy->neighbors).push_back(newNode);
                DFS(child, newNode, visited);
            }
            else
                (copy->neighbors).push_back(visited[child->val]);
        }        
        return copy;
    }
};