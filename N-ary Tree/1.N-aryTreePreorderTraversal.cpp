#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

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
    // recursive DFS
    void preorder(Node* root, vector<int>& ans){
        if(!root)
            return;
        
        ans.push_back(root->val);

        for (auto child :root->children)
            preorder(child, ans);        
    }
    // iterativelly DFS
    void preorder_iteratively(Node* root, vector<int>& ans){

        if(!root)
            return;

        stack<Node*> st;
        st.push(root);

        while (!st.empty())
        {
            Node* tmp = st.top();
            st.pop();

            ans.push_back(tmp->val);

            for(int i = tmp->children.size()-1; i>=0; i--)
                st.push(tmp->children[i]);         
        }       
    }
public:
    vector<int> preorder(Node* root) {

        vector<int> ans;
        preorder(root, ans);
        return ans;
        
    }
};