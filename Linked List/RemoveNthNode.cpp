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

        ListNode *cur = head, *back = head;
        
        while(n-- > 0) cur = cur->next;
        
        if(!cur) return head->next;
        
        while(cur->next){
            cur = cur->next;
            back = back->next;
        }
                 
        back->next = back->next->next;            
        return head;
    }
};

int main(){
    Solution s;

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
 
    ListNode* res = s.removeNthFromEnd(head,1);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->val;
    return 0;
}

