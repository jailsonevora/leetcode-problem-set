#include<iostream>
#include<algorithm>
#include<vector>
#include"Util\Include\BuildLinkedList.h"

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        
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