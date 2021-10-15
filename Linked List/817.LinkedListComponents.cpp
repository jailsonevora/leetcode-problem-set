#include<iostream>
#include<vector>
#include<unordered_set>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> set (nums.begin(), nums.end());
        int ans = 0;
        while (head) {
            if (set.count(head->val) && (head->next == NULL || !set.count(head->next->val))) 
                ans++;
            head = head->next;
        }
        return ans;
    }
};

int main(){
    
    ListNode* l1 = nullptr;

    Solution sl;
    BuildLinkedList bl;

    bl.pushBack(0, l1);
    bl.pushBack(1, l1);
    bl.pushBack(2, l1);
    bl.pushBack(3, l1);

    vector<int> nums = {
        0,1,3
    };

    cout << sl.numComponents(l1,nums);
}