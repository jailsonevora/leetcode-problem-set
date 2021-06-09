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

        if(head == curr->next && curr->val == val){
            head = head->next;
            curr->next = head;
        }

        while (curr)
        {
            if (curr->val == val)
                curr->next = curr->next->next;            
            curr = curr->next;
        }
        return head;
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
    ll.push(1);
    ll.push(2);
    ll.push(6);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);

    ListNode *h = ll.removeElements(ll.head, 6);
}
