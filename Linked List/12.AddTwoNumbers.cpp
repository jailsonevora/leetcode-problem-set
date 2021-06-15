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
            remainder = ( (!headL1) ? 0 : headL1->val ) + ( (!headL2) ? 0 : headL2->val ) + remainder;
            int lastDigit = remainder%10;
            remainder/=10;
            pushBack(headResult, lastDigit);

            if(headL1) headL1 = headL1->next;
            if(headL2) headL2 = headL2->next;
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
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);

    l2.pushBack(9);
    l2.pushBack(9);
    l2.pushBack(9);
    l1.pushBack(9);

    l1.addTwoNumbers(l1.head, l2.head);
}