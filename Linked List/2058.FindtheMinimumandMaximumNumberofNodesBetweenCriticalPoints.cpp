#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next, *prev = head;
        int min, max, i = 0;

        while (cur->next)
        {
            /* min critical point */
            if(cur->val < prev && cur->val < cur->next)
                min = std::min(i,min);
            /* max critical point */
            else if(cur->val > prev && cur->val > cur->next)
                max = std::max(i,max);

            prev = cur;
            cur = cur->next;
            i++;
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