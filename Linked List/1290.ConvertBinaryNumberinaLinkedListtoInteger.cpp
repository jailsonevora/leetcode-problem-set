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
    ListNode *head = NULL;

    long long binaryToDecimalVec(vector<int> n)
    {
        long long base = 1, decimal = 0;
        for (auto& lastD : n) {

            decimal += lastD * base;
            base = base * 2;
        }        
        return decimal;
    }

    long long binaryToDecimal(int n)
    {
        long long temp = n, base = 1, decimal = 0;
        while (temp) {
    
            long long lastD = temp % 10;
            temp = temp / 10;

            decimal += lastD * base;

            base = base * 2;
        }
        
        return decimal;
    }

    int getDecimalValue(ListNode* head) {

        if(!head)
            return;

        ListNode* curr = head;
        int binary = 1;
        while (curr)
            binary = 10 * binary + curr->val;

        return binaryToDecimal(binary); 
    }

    void pushBack(int data)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp; 
            return;
        }     
        while(curr && curr->next) curr = curr->next;
        curr->next = temp;
    }
};

int main(){
    
    Solution ll;
    ll.pushBack(1);
    ll.pushBack(0);
    ll.pushBack(1);
    // ll.pushBack(1);

    cout << ll.getDecimalValue(ll.head);
}