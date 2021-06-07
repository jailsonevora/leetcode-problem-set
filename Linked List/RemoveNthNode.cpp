#include <iostream>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *temp = new ListNode(0);
        temp->next = head;

        ListNode *cur = temp;
            
        while(n > 0){
            cur = cur->next;
            n--;
        }

        cur->next = cur->next->next;
        head = temp->next;
        n--;
    }
};

int main(){
    Solution s;

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
 
    /* Create a loop for testing */
    //head->next->next->next->next = head->next;
 
    ListNode* res = s.removeNthFromEnd(head,1);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->val;
    return 0;
}

