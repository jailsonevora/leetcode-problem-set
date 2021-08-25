#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        queue<Node*> queue;

        if(!root)
            return nullptr;

        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                Node* curr = queue.front();
                queue.pop();

                Node* prevRight = curr->right;

                if(curr->left){
                    curr->left->next = prevRight;
                    queue.push(curr->left);
                }
                else{
                    curr->left->next = nullptr;
                }
                
                if (curr->right){
                    curr->right->next = prevRight;
                    queue.push(curr->right);
                }                
                else{
                    curr->right->next = nullptr;
                }               
            }            
        }
        return root;        
    }
};