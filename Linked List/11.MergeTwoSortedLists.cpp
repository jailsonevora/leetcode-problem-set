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
        
    }

    void pushBack(int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) curr = curr->next;

        curr->next = temp;
    }
};

int main(){
    
    Solution lOne, lTwo;
    lOne.pushBack(1);
    lOne.pushBack(2);
    lOne.pushBack(4);

    lTwo.pushBack(1);
    lTwo.pushBack(3);
    lTwo.pushBack(4);

    cout << lOne.mergeTwoLists(lOne.head, lTwo.head);
}