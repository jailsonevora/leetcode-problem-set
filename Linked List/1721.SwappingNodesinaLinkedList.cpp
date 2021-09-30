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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* tail = head; int size = 1, end = k;
        while (tail->next)
            tail = tail->next,
            size++;

        ListNode* kthBegin = head;
        while (--k)
            kthBegin = kthBegin->next;

        int kthEnd = size - end;
        tail = head;
        while (kthEnd --)
            tail = tail->next;
        
        
        tail;
        
        
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
    
    ListNode* l1 = nullptr;

    Solution ll;
    ll.pushBack(1, l1);
    ll.pushBack(2, l1);
    ll.pushBack(3, l1);
    ll.pushBack(4, l1);
    ll.pushBack(5, l1);

    ll.swapNodes(l1,2);

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}