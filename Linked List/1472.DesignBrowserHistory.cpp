#include<iostream>
#include<vector>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class BrowserHistory {

    ListNodeString* curr = nullptr;

public:

    BrowserHistory(string homepage) {
        curr = new ListNodeString(homepage);       
    }
    
    void visit(string url) {
        curr->next = new ListNodeString(url);
        ListNodeString* prev = curr;
        curr = curr->next;
        curr->prev = prev;
    }
    
    string back(int steps) {

        while (steps-- && curr->prev)
            curr = curr->prev;
        return curr->val;
    }
    
    string forward(int steps) {

        while (steps-- && curr->next)
            curr = curr->next;
        return curr->val;
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