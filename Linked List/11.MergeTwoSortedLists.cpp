#include<iostream>
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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    ListNode *head = NULL;

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *headL1 = l1;
        ListNode *headL2 = l2;

        while (l1 != )
        {
            /* code */
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

        while(curr && curr->next) curr = curr->next;

        curr->next = temp;
    }
};

int main(){
    
    Solution L1, L2;
    L1.pushBack(1);
    L1.pushBack(2);
    L1.pushBack(4);

    L2.pushBack(1);
    L2.pushBack(3);
    L2.pushBack(4);

    L1.mergeTwoLists(L1.head, L2.head);
}