#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    
public:
    ListNode *head = NULL;

    // Binary Representation
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = head;
        long long binary = 0;
        while (curr){
            binary = (2 * binary) + curr->val;
            curr = curr->next;
        }
        return binary; 
    }

    // Bit Manipulation
    int getDecimalValue(ListNode* head) {
        
        ListNode* curr = head;
        long long binary = 0;
        while (curr){
            binary = (binary << 1) | curr->val;
            curr = curr->next;
        }
        return binary; 
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

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast = head, *slow = head;
        
        while(slow && slow->next){
            fast = fast->next;
            slow = slow->next->next;
        }
        return fast;        
    }
};

int main(){
    
    Solution ll;
    ll.pushBack(1);
    ll.pushBack(0);
    ll.pushBack(1);

    cout << ll.getDecimalValue(ll.head);
}