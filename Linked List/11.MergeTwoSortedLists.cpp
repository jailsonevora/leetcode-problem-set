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

        ListNode *headL1 = l1, *headL2 = l2, *headTemp;

        while (headL1 && headL2)
        {
            /* code */
            if (headL2->val <= headL1->val)
            {
                /* code */
                pushBack(head, tempNode);
            }
            else{

            }
            
        }
                
    }

    void pushBack(ListNode *head, ListNode *tempNode)
    {
        ListNode* curr = head;

        if (!head){  
            head = tempNode; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = tempNode;
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