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
    bool isPalindrome(ListNode* head) {
        ListNode *first = head, *last = head;
        ListNode *headHalf = NULL;

        while (1)
        {
            last = last->next->next;
            //odd linkedList
            if (last->next == NULL){
                headHalf = first->next->next;
                break;
            }
            //even linkedList
            if (last == NULL)
            {
                headHalf = first->next;
                break;
            }         
            first = first->next;
        }        
        //remove the odd midlle node;
        first->next = NULL;

        // now we reverse the second linkedList
                


        
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