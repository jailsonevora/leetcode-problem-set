#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;

        ListNode* first = head;
        ListNode* second = first->next;

        if (!second)
            return first;

        ListNode* third = swapPairs(second->next);       
                    
        second->next = first;
        first->next = third;

        return second;
    }
};
