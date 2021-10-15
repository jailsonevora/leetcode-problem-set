#include<iostream>
#include<vector>
#include<unordered_map>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
    }
};

int main(){
    
    ListNode* l1 = nullptr;

    Solution ll;
    ll.pushBack(1, l1);
    ll.pushBack(2, l1);
    ll.pushBack(3, l1);
    ll.pushBack(4, l1);
    ll.pushBack(5, l1);

    ll.swapNodes(l1,2);

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}