#include<iostream>
#include "Util\Include\LinkedListNode.h"

class Solution {
public:
    ListNode *head = NULL;
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;

        while (curr->next)
        {
            if (curr->next->val == val)
                curr->next = curr->next->next;
            else           
                curr = curr->next;
        }
        return dummy->next;
    }
    
    void pushBack(int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) curr = curr->next;

        curr->next = temp;
    }
};

int main(){

    Solution ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(6);
    ll.pushBack(3);
    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);

    ListNode *h = ll.removeElements(ll.head, 6);
}
