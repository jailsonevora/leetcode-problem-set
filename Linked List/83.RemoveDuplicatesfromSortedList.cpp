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

    ListNode* deleteDuplicates(ListNode* head) {
                
        ListNode* curr = head;
        
        while(curr && curr->next){
            ListNode* next = curr->next;
            if(next->val == curr->val)
                curr->next = next->next;
            else
                curr = next;
        }
        
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
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(3);

    l1.deleteDuplicates(l1.head);
}