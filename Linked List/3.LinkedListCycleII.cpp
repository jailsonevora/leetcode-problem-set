#include <iostream>
#include <set>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {    
public:
    ListNode *detectCycle(ListNode *head) {

        if (!head || !head->next)
            return NULL;
        
        ListNode *f = head, *s = head;
        
        while(f && f->next){
            s = s->next;
            f = f->next->next;       
            if(s == f) break;
        }
        
        if (s != f)
            return NULL;

        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }    
        return s;
    }
};

int main(){
    Solution s;

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
 
    /* Create a loop for testing */
    head->next->next->next->next = head->next;
 
    ListNode* res = s.detectCycle(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->val;
    return 0;
}

