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
class Solution {
public:
    ListNode *head = NULL;
    bool isPalindrome(ListNode* head) {
        
    }
};


int main(){
    
    Solution ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(2);
    ll.pushBack(1);

    cout << isPalindrome(ll.head);
}