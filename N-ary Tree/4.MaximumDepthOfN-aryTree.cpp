#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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
    //iteratively BFS level order
    int maxDepth(Node* root) {

        if(!root)
           return 0;

        queue<Node*> queue;
        int ans;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                Node* curr = queue.front();
                queue.pop();

                for(auto child: curr->children)
                    queue.push(child);                
            }
            ans++;            
        }
        return ans;        
    }
};