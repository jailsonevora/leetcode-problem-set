#include<iostream>
#include<algorithm>
#include<vector>
#include"Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {

        // find n
        int n = 0;        
        ListNode* curr = head;
        while (curr){
            n++;
            curr = curr->next;
        }

        // split linkedlist in two half
        int half = (n/2);
        ListNode* dummy = new ListNode(0) ;
        dummy->next = head;

        ListNode* halfHead = head;
        ListNode* currPrev = dummy;
        while (half--)
        {
            halfHead = halfHead->next;
            currPrev = currPrev->next;
        }
        currPrev->next = nullptr;

        // reverse the second half
        ListNode* prev = nullptr, *next = nullptr;
        curr = halfHead;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        halfHead = prev;
        



        return 0;
        
    }
};
int main(){

    Solution sl;
    ListNode* head = nullptr;

    BuildLinkedList bl;

    vector<int> data = {5,4,2,1};
    for(auto it: data)
        bl.pushBack(it, head);

    sl.pairSum(head);
}