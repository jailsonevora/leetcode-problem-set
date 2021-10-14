#include<iostream>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    
    ListNode *head = NULL;

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *headL1 = l1, *headL2 = l2, *headTemp = NULL;

        while (headL1 && headL2)
        {
            if (headL1->val <= headL2->val)
                pushBack(headTemp, headL1);
            else
                pushBack(headTemp, headL2);
        }

        while (headL1)
            pushBack(headTemp, headL1);

        while (headL2)
            pushBack(headTemp, headL2);
        
        return headTemp;
    }

    void pushBack(ListNode *&head, ListNode *&tempNode)
    {
        ListNode* curr = head;

        if (!head){  
            head = tempNode;
            tempNode = tempNode->next;
            head->next = NULL;
        } 
        else{

            while(curr && curr->next) 
                curr = curr->next;
            curr->next = tempNode;

            tempNode = tempNode->next;
            curr->next->next = NULL;
        }
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
    
    Solution l1, l2;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(4);

    l2.pushBack(1);
    l2.pushBack(3);
    l2.pushBack(4);

    l1.mergeTwoLists(l1.head, l2.head);
}