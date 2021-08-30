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