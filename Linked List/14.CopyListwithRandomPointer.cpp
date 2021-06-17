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

    void pushBack(int data, int index)
    {
        Node* temp = new Node(data);
        if (index == -1)            
            temp->random = nullptr;                

        Node* curr = head;
        while (index-- > 0)
            curr = curr->next;
        temp->random = curr;

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

    l1.pushBack(7, -1);
    l1.pushBack(13, 1);
    l1.pushBack(11, 5);
    l1.pushBack(10, 3);
    l1.pushBack(1, 1);

    l1.copyRandomList(l1.head);
}