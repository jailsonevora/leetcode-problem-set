#include<iostream>
#include<algorithm>
#include<vector>
#include"Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {

        int n = 0;

        ListNode* curr = head, *half;
        while (curr){
            n++;
            curr = curr->next;
        }

        int half = n/2;
        
        ListNode* dummy = new ListNode(0) ;
        dummy->next = head;

        curr = head;
        ListNode* currPrev = dummy;
        while (half--)
        {
            curr = curr->next;
            currPrev = currPrev->next;
        }
        currPrev = nullptr;
        
        
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