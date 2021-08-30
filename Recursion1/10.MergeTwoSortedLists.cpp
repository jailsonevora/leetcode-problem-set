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

        ListNode *headL1 = l1, *headL2 = l2, *headTemp = NULL;

        while (headL1 && headL2)
        {
            if (headL1->val <= headL2->val)
                pushBack(headTemp, headL1);
            else
                pushBack(headTemp, headL2);
        }

        while (headL1)
            pushBack(headTemp, headL1);

        while (headL2)
            pushBack(headTemp, headL2);
        
        return headTemp;
    }

    void pushBack(ListNode *&head, ListNode *&tempNode)
    {
        ListNode* curr = head;

        if (!head){  
            head = tempNode;
            tempNode = tempNode->next;
            head->next = NULL;
        } 
        else{

            while(curr && curr->next) 
                curr = curr->next;
            curr->next = tempNode;

            tempNode = tempNode->next;
            curr->next->next = NULL;
        }
    }