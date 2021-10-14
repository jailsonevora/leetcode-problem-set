#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


class Solution {
public:
    // BFS with queue
    Node* connect(Node* root) {

        if(!root)
            return nullptr;

        queue<Node*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            while (size--)
            {
                Node* curr = queue.front();
                queue.pop();

                if(!size)
                    curr->next = nullptr;
                else
                    curr->next = queue.front();

                if(curr->left)
                    queue.push(curr->left);
                
                if (curr->right)
                    queue.push(curr->right);
            }            
        }
        return root;        
    }
};