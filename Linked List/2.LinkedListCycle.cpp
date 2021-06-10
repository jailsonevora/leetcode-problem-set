#include <iostream>

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
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;            
            if(s == f) return true;
        }
        return false;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    Solution s;
    s.hasCycle(head);
    return 0;
}

