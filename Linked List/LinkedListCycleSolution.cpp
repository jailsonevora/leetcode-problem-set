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

        if (head == NULL || head->next == NULL)
            return false;

        ListNode *slowRunner = head, *fastRunner = head;
        
        for(;fastRunner != NULL && fastRunner->next != NULL;){
            slowRunner = slowRunner->next; fastRunner = fastRunner->next->next;
            if(slowRunner == fastRunner)
                return true;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        
        if (!head || !head->next)
            return false;       
        
        for(ListNode *slowRunner = head, *fastRunner = head->next->next; fastRunner && fastRunner->next; 
            slowRunner = slowRunner->next, fastRunner = fastRunner->next->next)
            if(slowRunner == fastRunner)
                return true;
        return false; 
    }
};

// if (head == NULL || head->next == NULL)
//         return false;

//         ListNode *slowRunner = head, *fastRunner = head;
        
//         while(fastRunner && fastRunner->next){
//             slowRunner = slowRunner->next;
//             fastRunner = fastRunner->next->next;
//             if(slowRunner == fastRunner)
//                 return true;
//         }
//         return false; 

int main(){
    ListNode *head = new ListNode(1);
    Solution s;
    s.hasCycle(head);
    return 0;
}

