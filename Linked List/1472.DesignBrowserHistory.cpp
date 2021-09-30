#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    string val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(string x) : val(x), next(nullptr) {}
    ListNode(string x, ListNode *next) : val(x), next(next) {}
};

class BrowserHistory {

    ListNode* history = nullptr, *curr = history;
    int size = 0;

    void pushBack(string data, ListNode*& head)
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
public:
    BrowserHistory(string homepage) {
        pushBack(homepage,history);
        curr = history;
        size++;        
    }
    
    void visit(string url) {
        pushBack(url,history);
        //if(history->next)
            curr = curr->next;
        size++;
    }
    
    string back(int steps) {

        ListNode* temp = history;
        int back = size - steps;

        while (back-- && temp->next)
        {
            temp = temp->next;
        }

        return temp->val;      
    }
    
    string forward(int steps) {

        ListNode* temp = curr;

        while (steps-- && temp->next)
        {
            temp = temp->next;
        }

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
    
    BrowserHistory* obj = new BrowserHistory("www.google.com");
    obj->visit("www.facebook.com");
    string param_2 = obj->back(1);
    string param_3 = obj->forward(1);
}