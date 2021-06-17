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
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode *head = nullptr;

    ListNode* rotateRight(ListNode* head, int k) {

        ListNode *second = head, *first = head;
        
        while (k-- > 0){
            if(!first->next) first = head; 
            first = first->next;
        }

        if (!first) return head->next;

        while (first->next){
            if(!first->next) first = head;
            if(!second->next) second = head;
            first = first->next;
            second = second->next; 
        }

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
    
    l1.pushBack(0);
    l1.pushBack(1);
    l1.pushBack(2);

    l1.rotateRight(l1.head, 4);
}