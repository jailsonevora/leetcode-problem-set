#include <iostream>
#include "Util\Include\LinkedListNode.h"

class Solution {
public:
    ListNode *head = NULL;

    void addAtTail(ListNode *remain, ListNode *headRemain) {
        
        if(headRemain != NULL){
            ListNode *cur = headRemain;

            while (cur->next != NULL)
                cur = cur->next;
            
            cur->next = remain;
        }
        else
            headRemain = remain;
    }

    ListNode* oddEvenList(ListNode* head) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy, *headRemain = curr, *last = head;

        int lenght = 1;
        while(last && last->next){
            lenght++; 
            last = last->next;            
        }
        int i = 1;
        while (curr->next && i <= lenght)
        {   
            if ((i % 2 == 0) && curr->next->next){
                ListNode *headRemain = curr->next;
                curr->next = curr->next->next;
                
                headRemain->next = nullptr;
                last->next = headRemain;                

                last = last->next;
            }
            else           
                curr = curr->next;
            i++;
        }
        return dummy->next;        
    }

    ListNode* oddEvenListT(ListNode* head) {
        if (head==nullptr) return head;
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;

        while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
        }
        odd->next = evenHead;
        return head;
    
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
    ll.pushBack(3);
    ll.pushBack(4);
    ll.pushBack(5);    
    ll.pushBack(6);
    ll.pushBack(7);
    ll.pushBack(8);

    ListNode *h = ll.oddEvenList(ll.head);
}