#include<iostream>
#include "Util\Include\LinkedListNode.h"

class Solution {
public:
    ListNode *head;
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = NULL, *next = NULL, *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
    void push(int data)
    {
        ListNode* temp = new ListNode(data);
        temp->next = head;
        head = temp;
    }
    void print()
    {
        struct ListNode* temp = head;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Solution ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    ListNode *h = ll.reverseList(ll.head);
}