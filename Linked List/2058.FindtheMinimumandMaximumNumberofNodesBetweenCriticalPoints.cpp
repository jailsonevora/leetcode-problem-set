#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next;
        int i = 1, prev = head->val;
        vector<int> min, max;

        while (cur->next)
        {
            /* all min critical point */
            if(cur->val < prev && cur->val < cur->next->val)
                min.push_back(i);
            /* all max critical point */
            else if(cur->val > prev && cur->val > cur->next->val)
                max.push_back(i);

            prev = cur->val;
            cur = cur->next;
            i++;
        }
        
        return {};
        
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