#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next, *prev = head;
        vector<int> min, max;
        int i = 0;

        while (cur->next)
        {
            /* min critical point */
            if(cur->val < prev && cur->val < cur->next)
                min.push_back(i);
            /* max critical point */
            else if(cur->val > prev && cur->val > cur->next)
                max.push_back(i);

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