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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *head;
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;

        while (curr->next)
        {
            if (curr->val == val)
                curr->next = curr->next->next;
            curr = curr->next;
        }
    }
    
    void push(int data)
    {
        ListNode* temp = new ListNode(data);
        temp->next = head;
        head = temp;
    }
};

int main(){
    Solution ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    ListNode *h = ll.removeElements(ll.head, 2);
}
