#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
    }
};

int main(){
    
    ListNode* l1 = nullptr, *l2 = nullptr;

    Solution ll;
    ll.pushBack(0, l1);
    ll.pushBack(1, l1);
    ll.pushBack(2, l1);
    ll.pushBack(3, l1);
    ll.pushBack(4, l1);
    ll.pushBack(5, l1);

    ll.pushBack(1000000, l2);
    ll.pushBack(1000001, l2);
    ll.pushBack(1000002, l2);

    ll.mergeInBetween(l1, 3, 4, l2);

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}