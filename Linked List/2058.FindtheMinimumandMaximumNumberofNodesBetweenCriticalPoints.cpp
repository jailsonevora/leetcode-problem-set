#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next, *prev = head;

        while (cur->next)
        {
            /* code */
        }
        

        
    }
};

int main(){
    
    ListNode* head = nullptr;

    Solution sl;
    BuildLinkedList bl;
    bl.pushBack(5, head);
    bl.pushBack(3, head);
    bl.pushBack(1, head);
    bl.pushBack(2, head);
    bl.pushBack(5, head);
    bl.pushBack(1, head);
    bl.pushBack(2, head);

    sl.nodesBetweenCriticalPoints(head);
}