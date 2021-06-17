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

    void random(int index, int indexRandom)
    {
        Node* curr = head;       
        
        while (index-- > 0)
            curr = curr->next;

        Node* tempCurr = head;
        if (indexRandom == -1){            
            curr->random = nullptr;
            return;
        }          
        while (indexRandom-- > 0)
            tempCurr = tempCurr->next;    
        curr->random = tempCurr;
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
    l1.random(1, -1);
    l1.random(2, 1);
    l1.random(3, 5);
    l1.random(4, 3);
    l1.random(5, 1);

    l1.copyRandomList(l1.head);
}