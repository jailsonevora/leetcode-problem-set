#include<iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

using namespace std;

struct Node {
    int val;
    Node *next;
    Node* random;
    Node(int x) : val(x), random(nullptr), next(nullptr) {}
};

class Solution {
public:

    Node *head = nullptr;

    Node* copyRandomList(Node* head) {
        
    }

    void pushBack(int data, Node *l)
    {
        Node* temp = new Node(data);
        temp->random = l;
        Node* curr = head;

        if (!head){  
            head = temp;
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }
};

int main(){

    Solution l1;

    l1.pushBack(1, nullptr);
    l1.pushBack(2, nullptr);
    l1.pushBack(3, l2.head);
    l1.pushBack(4, nullptr);
    l1.pushBack(5, nullptr);
    l1.pushBack(6, nullptr);

    l1.copyRandomList(l1.head);
}