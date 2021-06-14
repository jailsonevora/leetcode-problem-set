#include<iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    }
};

int main(){
    
    Solution ll;
    ll.pushBack(1);
    // ll.pushBack(2);
    // ll.pushBack(2);
    // ll.pushBack(1);

    cout << ll.mergeTwoLists(ll.head);
}