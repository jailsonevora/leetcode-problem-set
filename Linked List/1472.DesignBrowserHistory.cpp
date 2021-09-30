#include<iostream>
#include<vector>

using namespace std;

class BrowserHistory {

    //Definition for singly-linked list.    
    struct ListNode {
        string val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(string x) : val(x), next(nullptr) {}
        ListNode(string x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* head = nullptr, *curr = head, *tail = nullptr;
    int size = 0, currSize = 0;

    void pushBack(string data, ListNode*& head)
    {
        ListNode* temp = new ListNode(data);
        ListNode* curr = head;

        if (!head){  
            head = temp;
            tail = head; 
            return;
        }     
        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;

        tail = curr->next;
    }

public:

    BrowserHistory(string homepage) {
        pushBack(homepage,head);
        curr = tail;
        size++;
        currSize = size;        
    }
    
    void visit(string url) {
        pushBack(url,head);
        curr = tail;
        size++;
        currSize = size;
    }
    
    string back(int steps) {

        ListNode* temp = head;
        int back = abs(currSize - steps);
        int b = 0;

        while (--back && temp->next){
            temp = temp->next;
            b++;
        }

        curr = temp;
        currSize -= b;
        return temp->val;      
    }
    
    string forward(int steps) {

        ListNode* temp = curr;
        int b = 0;

        while (steps-- && temp->next){
            temp = temp->next;
            b ++;
        }

        
        curr = temp;
        currSize += b;
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){
    
    BrowserHistory* obj = new BrowserHistory("www.leetcode.com");
    obj->visit("www.googgle.com");
    obj->visit("www.facebook.com");
    obj->visit("www.youtube.com");

    cout << obj->back(1) << "\n";
    cout << obj->back(1) << "\n";

    cout << obj->forward(1) << "\n";

    obj->visit("www.linkedin.com"); 

    cout << obj->forward(2) << "\n";

    cout << obj->back(2) << "\n";
    cout << obj->back(7) << "\n";





}