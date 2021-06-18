#include<iostream>
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

    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || k == 0) return head;

        ListNode *tail = head;
        int lenght = 1;
               
        while (tail->next){
            lenght++;            
            tail = tail->next;
        }
        tail->next = head;
        int rotatePoint = lenght - k % lenght;

        tail = head;
        while (rotatePoint-- > 1)
            tail = tail->next;

        head = tail->next;        
        tail->next = nullptr; 
        return head;        
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
    
    Solution l1;
    // l1.pushBack(1);
    // l1.pushBack(2);
    // l1.pushBack(3);
    // l1.pushBack(4);
    // l1.pushBack(5);
    
    //l1.pushBack(0);
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);

    l1.rotateRight(l1.head,2000000000);
}