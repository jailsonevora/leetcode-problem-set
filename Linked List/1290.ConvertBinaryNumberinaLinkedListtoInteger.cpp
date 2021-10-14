#include<iostream>
#include<vector>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
    
public:
    ListNode *head = NULL;

    // Binary Representation
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = head;
        long long binary = 0;
        while (curr){
            binary = (2 * binary) + curr->val;
            curr = curr->next;
        }
        return binary; 
    }

    // Bit Manipulation
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = head;
        long long binary = 0;
        while (curr){
            binary = (binary << 1) | curr->val;
            curr = curr->next;
        }
        return binary; 
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
    ll.pushBack(0);
    ll.pushBack(1);

    cout << ll.getDecimalValue(ll.head);
}