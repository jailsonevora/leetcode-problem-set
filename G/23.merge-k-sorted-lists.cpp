/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include<algorithm>
#include<vector>
#include<Util\Include\BuildLinkedList.h>
#include<queue>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int,vector<int>, greater<>> pq;

        for(auto it: lists){
            ListNode* c = it;
            while (c)
            {                
                pq.push(c->val);
                c = c->next;
            }           
        }

        ListNode* head = nullptr, *curr = head;
        while (!pq.empty())
        {
            int val = pq.top();
            pq.pop();

            ListNode* tmp = new ListNode(val);

            if(!head){
                head = tmp;
                curr = head;
            }
            else{
                curr->next = tmp;
                curr = curr->next;
            }
        }
        return head;        
    }
};
// @lc code=end
int main(){

    Solution sl;
    ListNode* head = nullptr;
    vector<ListNode*> lists;

    BuildLinkedList bl;

    vector<vector<int>> data = {{1,4,5},{1,3,4},{2,6}};
    for(auto it: data){
        ListNode* head = nullptr;
        for(auto i: it)
            bl.pushBack(i, head);
        lists.push_back(head);
    }
    sl.mergeKLists(lists);
}
