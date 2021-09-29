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

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        
    }
    
    void visit(string url) {
        
    }
    
    string back(int steps) {
        
    }
    
    string forward(int steps) {
        
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
    
    ListNode* l1 = nullptr, *l2 = nullptr;

    BrowserHistory ll;

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}