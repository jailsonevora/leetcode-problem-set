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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode *head = nullptr;

    ListNode* rotateRight(ListNode* head, int k) {

        // ListNode *temp = new ListNode(-1);
        // temp->next = head;
        ListNode *second = head, *first = head;

        if (k == 0 || !head->next)
            return head;
        if (!head)
            return nullptr;     
               
        while (k-- > 0){

            if(!first->next) 
                first = head;
            else
                first = first->next;
        }

        while (first->next){

            if(!first->next) 
                first = head;
            else
                first = first->next;

            if(!second->next) 
                second = head;
            else
                second = second->next; 
        }

        if(!second->next)
            second->next = head;

        ListNode *remain = second->next;
        second->next = nullptr;

        first->next = head;
        head = remain;        
        return head;
    }

    void pushBack(int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }
};

int main(){
    
    Solution l1;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);
    l1.pushBack(5);
    
    // l1.pushBack(0);
    // l1.pushBack(1);
    // l1.pushBack(2);

    l1.rotateRight(l1.head, 2);
}