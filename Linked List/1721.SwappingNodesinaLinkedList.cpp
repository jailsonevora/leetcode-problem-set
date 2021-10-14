#include<iostream>
#include<vector>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution { 
public:
    // using array and two pointers
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* curr = head;
        int listSize = 0;

        vector<int> listToArray;

        while (curr)
            listToArray.push_back(curr->val),
            curr = curr->next, listSize++;

        swap(listToArray[k-1], listToArray[(listSize)-(k)]);
        
        curr = head;
        int i = 0;
        while(curr){
            curr->val = listToArray[i];
            i++;
            curr = curr->next;
        }        

        return head;
    }

    //one pass
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = nullptr, *n2 = nullptr;
        for (auto p = head; p != nullptr; p = p->next) {
            n2 = n2 == nullptr ? nullptr : n2->next;
            if (--k == 0) {
                n1 = p;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
        return head;
    }

    // 2 pass
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
    
    // two pointers 3 pass
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* tail = head;
        int listSize = 1;

        while (tail->next)
            tail = tail->next, listSize++;

        int kBegin = k-1;
        ListNode* beginPrev = head;
        while (kBegin--)
            beginPrev = beginPrev->next;

        int kEnd = listSize - k;
        ListNode* endPrev = head;
        while (kEnd--)
            endPrev = endPrev->next;

        swap(beginPrev->val, endPrev->val);
        return head;
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