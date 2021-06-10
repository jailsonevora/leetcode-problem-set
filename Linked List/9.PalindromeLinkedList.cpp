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

    ListNode *reverseList(ListNode *headHalf) {
        
        ListNode *prev = NULL, *next = NULL, *curr = headHalf;

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
    ll.pushBack(2);
    ll.pushBack(2);
    ll.pushBack(1);

    cout << ll.isPalindrome(ll.head);
}