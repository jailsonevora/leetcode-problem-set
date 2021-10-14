#include<iostream>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    ListNode *head = nullptr;

    ListNode* deleteDuplicates(ListNode* head) {
                
        ListNode* curr = head;
        
        while(curr && curr->next){
            ListNode* next = curr->next;
            if(next->val == curr->val)
                curr->next = next->next;
            else
                curr = next;
        }
        
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

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }
};

int main(){
    
    Solution l1;    
    l1.pushBack(1);
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(3);

    l1.deleteDuplicates(l1.head);
}