#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"
#include<algorithm>

using namespace std;

class Solution {
public:
    // O(N) time complexity
    // O(N) space complexity
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* cur = head->next;
        int i = 2, prev = head->val;
        vector<int> index;

        while (cur->next)
        {
            /* all min critical point */
            if(cur->val < prev && cur->val < cur->next->val)
                index.push_back(i);
            /* all max critical point */
            else if(cur->val > prev && cur->val > cur->next->val)
                index.push_back(i);

            prev = cur->val;
            cur = cur->next;
            i++;
        }

        if(index.size() < 2) 
            return {-1,-1};

        int mindist=INT_MAX;
        for(int i=0;i<index.size()-1;i++)
            mindist=min(index[i+1]-index[i],mindist);
        return {mindist,index.back()-index[0]};
        
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