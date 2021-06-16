#include<iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode* child;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:

    ListNode *head = nullptr;

    ListNode* flatten(ListNode* head) {

        ListNode *curr = head;

        while (curr)
        {
            if(curr->child){
                curr->next = curr->child;
                curr->child->prev = curr; 
                curr = curr->child;
            }

            curr= curr->next;
        }
        
        
    }

    void pushBack(ListNode *&head, int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }

    void pushBack(int data, ListNode *l)
    {
        ListNode* temp = new ListNode(data);
        temp->child = l;
        ListNode* curr = head;

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

    Solution l1, l2, l3;
    l1.pushBack(1, nullptr);
    l1.pushBack(2, nullptr);
    l1.pushBack(3, l2);
    l1.pushBack(4, nullptr);
    l1.pushBack(5, nullptr);
    l1.pushBack(6, nullptr);

    l1.flatten(l1.head);
}