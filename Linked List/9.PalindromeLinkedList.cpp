#include<iostream>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    ListNode *head = NULL;

    ListNode *reverseList(ListNode *headHalf) {
        
        ListNode *prev = NULL, *next = NULL, *curr = headHalf;

        if(!headHalf->next)
            return headHalf;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        headHalf = prev;
        return headHalf;
    }

    bool isPalindrome(ListNode* head) {

        ListNode *first = head, *last = head;
        ListNode *headHalf;

        if(!head->next)
            return true;

        while (1)
        {
            last = last->next->next;
            //odd linkedList
            if (last && !last->next){
                headHalf = first->next->next;
                break;
            }
            //even linkedList
            if (!last)
            {
                headHalf = first->next;
                break;
            }         
            first = first->next;
        }        
        //remove the odd midlle node;
        first->next = NULL;

        // now we reverse the second linkedList
        headHalf = reverseList(headHalf);

        //compare both head and headhalf
        ListNode *currHead = head, *currHeadHalf = headHalf;

        while (currHead && currHeadHalf){
            if(currHead->val != currHeadHalf->val)
                return false;
            currHead = currHead->next;
            currHeadHalf = currHeadHalf->next;
        }
        return true;
    }

    bool isPalindromeLeetCode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* nex;
        
        while(fast && fast->next){
            fast =fast->next->next;
            nex = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nex;
        }
        slow = (fast ? slow->next : slow);
        while(slow){
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
        
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
    
    Solution ll;
    ll.pushBack(1);
    // ll.pushBack(2);
    // ll.pushBack(2);
    // ll.pushBack(1);

    cout << ll.isPalindrome(ll.head);
}