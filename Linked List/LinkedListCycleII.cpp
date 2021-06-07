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
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;

        s = s->next;
        f = f->next->next;

        while(f && f->next){
            if(s == f) break;
            s = s->next;
            f = f->next->next;            
        }
        // If loop does not exist
        if (s != f)
            return NULL;

        s = head;
        while (s != f) {
            s = f->next;
            f = f->next;
        }    
        return s;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    Solution s;
    s.detectCycle(head);
    return 0;
}

