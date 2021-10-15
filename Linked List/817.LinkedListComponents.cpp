#include<iostream>
#include<vector>
#include<unordered_map>
#include "Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
    bool binarySearch(vector<int>& nums, int target) {
        
        int head = 0, tail = nums.size() - 1;

        while(head <= tail)
        {
            int middle = head + (tail - head) / 2;
            if(nums[middle] == target)
                return true;
            else if(nums[middle] < target)
                head = middle + 1;
            else
                tail = middle - 1;
        }       
        return false;        
    }
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_map<int,int> mp;
        ListNode* curr = head;

        while (curr && curr->next)
            mp.insert({curr->val,curr->next->val});
        
        int count = 0;
        for(auto [key, val]: mp)
            if(binarySearch(nums, val))
                count++;
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

    sl.numComponents(l1,nums);
}