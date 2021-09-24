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
        
        ListNode* aPtr = list1, *bPtr = list1;
        ListNode* tailL2 = list2;

        while (b--)
            bPtr = bPtr->next;

        a -= 1;
        while (a--)
            aPtr = aPtr->next;

        while (tailL2->next)
            tailL2 = tailL2->next;

        aPtr->next = list2;
        tailL2->next = bPtr->next;

        aPtr = nullptr, bPtr = nullptr, tailL2 = nullptr;
        delete aPtr, bPtr, tailL2;
        
        return list1;        
    }

    void pushBack(int data, ListNode*& head)
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