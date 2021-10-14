#include<iostream>
#include<vector>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    ListNode *head = NULL;

    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast = head, *slow = head;
        
        while(slow && slow->next){
            fast = fast->next;
            slow = slow->next->next;
        }
        return fast;        
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

    cout << ll.middleNode(ll.head);
}