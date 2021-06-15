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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode *head = nullptr;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *headL1 = l1, *headL2 = l2;
        ListNode *headResult = nullptr;

        int remainder = 0;

        while (headL1 || headL2)
        {
            if(!headL1) headL1->val = 0; else headL1;
            if(!headL2) headL2->val = 0; else headL2;

            remainder = headL1->val + headL2->val + remainder;
            int lastDigit = remainder%10;
            remainder/=10;
            pushBack(headResult, lastDigit);
        }

        return headResult;
    }

    void pushBack(ListNode *&head, int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }

    void pushBack(int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }
};


int main(){
    
    Solution l1, l2;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(4);

    l2.pushBack(1);
    l2.pushBack(3);
    l2.pushBack(4);

    l1.addTwoNumbers(l1.head, l2.head);
}