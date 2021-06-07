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
        ListNode *slowRunner = head, *fastRunner = head;
        
        for(;slowRunner != fastRunner; slowRunner->next, fastRunner->next->next)
            if(fastRunner->next == NULL)
                return false;
        return true;  
    }
};

int main(){
    ListNode *head = new ListNode(1);
    Solution s;
    s.hasCycle(head);
    return 0;
}

