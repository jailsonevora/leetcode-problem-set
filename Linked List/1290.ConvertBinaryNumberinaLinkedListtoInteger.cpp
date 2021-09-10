#include<iostream>

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

    int getDecimalValue(ListNode* head) {
        
    }
    static void pushBack(int data)
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

    cout << ll.getDecimalValue(ll.head);
}