#include "Util\Include\BuildLinkedList.h"

void BuildLinkedList::pushBack(int data, ListNode*& head)
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