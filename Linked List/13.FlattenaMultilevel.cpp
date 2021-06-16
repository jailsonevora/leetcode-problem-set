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
        ListNode *dumy = new ListNode(-1);
        dumy->next = head;
        head->prev = dumy;
        ListNode *curr = dumy;

        while (curr->next)
        {
            if(curr->next->child){
                curr->next->next = curr->next->child;
                curr->next->child->prev = curr->next;

                ListNode *dumyTwo = new ListNode(-1);
                dumyTwo->next = curr->next->child;

                curr = dumyTwo;
            }
            else
                curr= curr->next;
        }
        
        
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

    l3.pushBack(11, nullptr);
    l3.pushBack(12, nullptr);

    l2.pushBack(7, nullptr);
    l2.pushBack(8, l3.head);
    l2.pushBack(9, nullptr);
    l2.pushBack(10, nullptr);

    l1.pushBack(1, nullptr);
    l1.pushBack(2, nullptr);
    l1.pushBack(3, l2.head);
    l1.pushBack(4, nullptr);
    l1.pushBack(5, nullptr);
    l1.pushBack(6, nullptr);

    l1.flatten(l1.head);
}