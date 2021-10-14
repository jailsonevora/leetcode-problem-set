#include<iostream>
#include<vector>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    ListNode *head = NULL;

    void deleteNode(ListNode* node) {

        ListNode* curr = node;        
        swap(node->val, node->next->val);

        curr->next = curr->next->next;
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
    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(1);
    ll.pushBack(9);

    ListNode* node = ll.head->next;

    ll.deleteNode(node);
}