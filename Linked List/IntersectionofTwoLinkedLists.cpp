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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (!headA || !headA->next || !headB || !headB->next)
            return NULL;
        
        ListNode *f = headA, *s = headB;
        
        while(f && f->next && s && s->next){
            s = s->next;
            f = f->next->next;       
            if(s == f) break;
        }
        
        if (s != f)
            return NULL;

        s = headB;
        while (s != f) {
            s = s->next;
            f = f->next;
        }    
        return s;
    }
};

int main(){
    Solution s;

    // headA
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    //headB
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    headB->next->next->next = headA->next->next->next;
    headB->next->next->next->next = headA->next->next->next->next;
 
    ListNode* res = s.getIntersectionNode(headA, headB);

    if (res == NULL)
        cout << "The two lists do not intersect";
    else
        cout << "The intersected node's value is " << res->val;
    return 0;
}

