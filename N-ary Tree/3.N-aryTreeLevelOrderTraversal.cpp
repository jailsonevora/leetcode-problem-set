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
    //recursive
    void helper(Node* root, vector<vector<int>>&res,int level){
        if(!root)    return;
        if(res.size()==level)res.push_back({});
        res[level].push_back(root->val);
        for(Node* node:root->children){
            helper(node,res,level+1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {

        if(!root)
           return{};

        queue<Node*> queue;
        vector<vector<int>> ans;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                Node* curr = queue.front();
                queue.pop();
                tmp.push_back(curr->val);

                for(auto child: curr->children)
                    queue.push(child);                
            }
            ans.push_back(tmp);            
        }
        return ans;        
    }
    // recursive
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        helper(root,res,0);
        return res;
    }
};