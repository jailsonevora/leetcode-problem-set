#include<iostream>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:

    ListNode *head = nullptr;

    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || k == 0) return head;

        ListNode *tail = head;
        int lenght = 1;
               
        while (tail->next){
            lenght++;            
            tail = tail->next;
        }
        tail->next = head;
        int rotatePoint = lenght - k % lenght;

        tail = head;
        while (rotatePoint-- > 1)
            tail = tail->next;

        head = tail->next;        
        tail->next = nullptr; 
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
    // l1.pushBack(1);
    // l1.pushBack(2);
    // l1.pushBack(3);
    // l1.pushBack(4);
    // l1.pushBack(5);
    
    //l1.pushBack(0);
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);

    l1.rotateRight(l1.head,2000000000);
}