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
public:
    Node* cloneGraph(Node* node) {

        Node* t = new Node();
        return t;
        
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
    
    vector<Node*> graph[adjList.size()];
    for(int i = 0; i < adjList.size(); i++){
        for(int edge: adjList[i]){
                graph[i+1].push_back(new Node(edge));
        }
    }
    int w = 0;
    Solution sl;
    auto s = graph[1];
    sl.cloneGraph(s);
    
}

