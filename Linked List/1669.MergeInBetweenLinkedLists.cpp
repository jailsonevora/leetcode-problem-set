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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
    }
};

int main(){
    
    Solution ll;
    ll.pushBack(1);
    ll.pushBack(0);
    ll.pushBack(1);

    cout << ll.getDecimalValue(ll.head);
}