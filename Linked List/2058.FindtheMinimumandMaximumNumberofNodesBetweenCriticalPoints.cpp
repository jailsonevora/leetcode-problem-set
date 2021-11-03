#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next;
        int i = 2, prev = head->val;
        vector<int> minV, maxV;

        while (cur->next)
        {
            /* all min critical point */
            if(cur->val < prev && cur->val < cur->next->val)
                minV.push_back(i);
            /* all max critical point */
            else if(cur->val > prev && cur->val > cur->next->val)
                maxV.push_back(i);

            prev = cur->val;
            cur = cur->next;
            i++;
        }

        sort(maxV.begin(), maxV.end());
        sort(minV.begin(), minV.end());

        int mindistance = std::max(maxV[0],minV[minV.size()-1]);
        //int maxdistance = 
        return {
           
        };
        
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