/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/**/
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
    void dfs(Node* u, Node* v, vector<Node*>& visited){

        visited[v->val] = v;
        for(Node* child: u->neighbors){
            if(!visited[child->val]){
                Node* tmp = new Node(child->val);
                v->neighbors.push_back(tmp);
                dfs(child,tmp,visited);
            }
            else
                v->neighbors.push_back(visited[child->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {

        if(!node)
            return nullptr;

        vector<Node*> visited(1000,nullptr);
        Node* cp = new Node(node->val);

        visited[node->val] = cp;
        for(Node* child: node->neighbors){
            if(!visited[child->val]){
                Node* temp = new Node(child->val); 
                cp->neighbors.push_back(temp);
                dfs(child, temp, visited);
            }
            else
                cp->neighbors.push_back(visited[child->val]);
        }
        return cp;
    }
};
// @lc code=end
int main(){
    vector<vector<int>> adjList = {
        {2,4},
        {1,3},
        {2,4},
        {1,3}
    };

    vector<Node*> visited(1000,NULL);
    for (int i = 0; i < adjList.size(); i++)
    {
        Node* node = new Node(i+1);
        visited[i+1] = node;    
        for(int edge: adjList[i]){
            if(!visited[edge]){
                Node* newNode = new Node(edge);
                (node->neighbors).push_back(newNode);
            }
            else
                (node->neighbors).push_back(visited[edge]);
        }
    }

    Solution sl;
    cout << sl.cloneGraph(visited[1])->val;
}

