#include<iostream>
#include<vector>
#include<stack>

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
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* curr = head;
        vector<int> ans;
        stack<int> stack;

        int i = 0;
        while (curr)
        {
            /* code */
            while (!stack.empty() && stack.top() <= curr->val)
                stack.pop();

            ans.push_back(stack.empty() ? 0 : stack.top());
            stack.push(curr->val);
        }

        return ans;    
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
    ll.pushBack(2, l1);
    ll.pushBack(1, l1);
    ll.pushBack(5, l1);

    // Solution ll;
    // ll.pushBack(2, l1);
    // ll.pushBack(7, l1);
    // ll.pushBack(4, l1);
    // ll.pushBack(3, l1);
    // ll.pushBack(5, l1);

    for(auto it: ll.nextLargerNodes(l1))
        cout << "[" << it << "," << "]";
}