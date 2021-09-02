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
    void postorder(Node* root, vector<int>& ans){
        
        if(!root)
            return;

        for (auto child :root->children)
            postorder(child, ans);

        ans.push_back(root->val);        
    }

    // iterativelly DFS
    void postorder_iteratively(Node* root, vector<int>& ans){

        if(!root)
            return;

        stack<Node*> st;
        st.push(root);

        while (!st.empty())
        {
            Node* tmp = st.top();

            for (auto child : tmp->children)
                st.push(child);

            ans.push_back(tmp->val);
            st.pop();
        }  
        reverse(ans.begin(), ans.end());     
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};