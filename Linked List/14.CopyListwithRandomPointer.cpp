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

    void pushBack(int data)
    {
        Node* temp = new Node(data);              

        Node* curr = head;

        if (!head){  
            head = temp;
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }

    void random(int val, int index)
    {
        Node* tempCurr = head;
        if (index == -1)            
            tempCurr->random = nullptr;            
        
        while (index-- > 0)
            tempCurr = tempCurr->next;
        tempCurr->random = tempCurr;
    }
};

int main(){

    Solution l1;

    l1.pushBack(7);
    l1.pushBack(13);
    l1.pushBack(11);
    l1.pushBack(10);
    l1.pushBack(1);

    // fill ramdom pointer
    l1.random(7, -1);
    l1.random(13, 1);
    l1.random(11, 5);
    l1.random(10, 3);
    l1.random(1, 1);

    l1.copyRandomList(l1.head);
}