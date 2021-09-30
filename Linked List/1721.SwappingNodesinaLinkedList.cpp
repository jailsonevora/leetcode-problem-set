#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { 
public:
    // ListNode* swapNodes(ListNode* head, int k) {

    //     ListNode* tail = head;
    //     int listSize = 1;

    //     while (tail->next)
    //         tail = tail->next, listSize++;

    //     int kBegin = k-1;
    //     ListNode* beginPrev = head;
    //     while (--kBegin)
    //         beginPrev = beginPrev->next;

    //     int kEnd = listSize - k;
    //     ListNode* endPrev = head;
    //     while (--kEnd)
    //         endPrev = endPrev->next;

    //     ListNode* beginNext = beginPrev->next, *endNext = endPrev->next;

    //     beginNext->next = endNext->next;
    //     beginPrev->next =  endNext;
    //     endNext->next = endPrev;
    //     endPrev->next = beginNext;
    // }

    
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* curr = head;
        int listSize = 0;

        vector<int> listToArray;

        while (curr)
            listToArray.push_back(curr->val),
            curr = curr->next, listSize++;

        swap(listToArray[k-1], listToArray[(listSize)-(k)]);
        
        curr = head;
        int i = 0;
        while(curr){
            curr->val = listToArray[i];
            i++;
            curr = curr->next;
        }        

        return head;
    }

    void pushBack(int data, ListNode*& head)
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
    
    ListNode* l1 = nullptr;

    Solution ll;
    ll.pushBack(1, l1);
    ll.pushBack(2, l1);
    ll.pushBack(3, l1);
    ll.pushBack(4, l1);
    ll.pushBack(5, l1);

    ll.swapNodes(l1,2);

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}