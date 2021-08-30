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
public:

    ListNode *head = NULL;

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val >= l2->val)
            l2->next = mergeTwoLists(l1,l2->next);
        else
        {
            l1->next=mergeTwoLists(l1->next,l2);
            l2=l1;
        }
        return l2;
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