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

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;

        ListNode* aPtr = dummy, *bPtr = dummy;

        while (bPtr->next->val != b)
            bPtr = bPtr->next;

        while (aPtr->next->val != b)
            aPtr = aPtr->next;
        
        

    }

    void pushBack(int data, ListNode*& head)
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
    
    ListNode* l1 = nullptr, *l2 = nullptr;

    Solution ll;
    ll.pushBack(0, l1);
    ll.pushBack(1, l1);
    ll.pushBack(2, l1);
    ll.pushBack(3, l1);
    ll.pushBack(4, l1);
    ll.pushBack(5, l1);

    ll.pushBack(1000000, l2);
    ll.pushBack(1000001, l2);
    ll.pushBack(1000002, l2);

    ll.mergeInBetween(l1, 3, 4, l2);
}