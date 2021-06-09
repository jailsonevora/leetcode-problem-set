#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
        ListNode *curr = dummy, *headRemain = curr, *last;

        while(last && last->next) last = last->next;

        int i = 1;
        while (curr->next)
        {   
            if ((i % 2 == 0)){
                ListNode *headRemain = curr->next;
                curr->next = curr->next->next;
                
                last->next = headRemain->next->next;
                last = last->next;
            }
            else {          
                curr = curr->next;
            i++;
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

    ListNode *h = ll.oddEvenList(ll.head);
}