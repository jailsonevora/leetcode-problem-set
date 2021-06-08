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
    ListNode *head;
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev = NULL, *next = NULL, *curr = head;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
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
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
}