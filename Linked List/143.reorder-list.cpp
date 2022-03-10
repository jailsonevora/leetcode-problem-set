/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
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
#include<iostream>
#include<vector>
#include<Util\Include\BuildLinkedList.h>

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy, *slow = dummy;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr, *next = nullptr, *curr = middle;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* curr1 = head, *curr2 = middle;
        while (curr1 && curr2)
        {
            /* code */
        }
        
        

        
        
    }
};
// @lc code=end
int main(){

    Solution sl;
    ListNode* head = nullptr;

    BuildLinkedList bl;

    vector<int> data = {1,2,3,4};
    for(auto it: data)
        bl.pushBack(it,head);
    sl.reorderList(head);
}

