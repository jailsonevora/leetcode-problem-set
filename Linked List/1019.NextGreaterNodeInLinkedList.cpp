#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include "Util\Include\LinkedListNode.h"

using namespace std;

class Solution {
public:
    // monotonic stack with stack<>
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* curr = head;
        vector<int> ans, nums;
        stack<int> stack;

        while (curr)
            nums.push_back(curr->val),
                curr = curr->next;

        // using monotonic stack
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!stack.empty() && stack.top() <= nums[i])
                stack.pop();

            ans.push_back(stack.empty() ? 0 : stack.top());
            stack.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;    
    }

    // monotonic stack with vector<>
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ans, stack;

        // using monotonic stack
        for (ListNode* curr = head; curr; curr = curr->next)
        {
            while (stack.size() && ans[stack.back()] < curr->val)
                ans[stack.back()] = curr->val,
                    stack.pop_back();

            stack.push_back(ans.size());
            ans.push_back(curr->val);
        }

        for (int i: stack) 
            ans[i] = 0;

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

    // Solution ll;
    // ll.pushBack(2, l1);
    // ll.pushBack(1, l1);
    // ll.pushBack(5, l1);

    Solution ll;
    ll.pushBack(2, l1);
    ll.pushBack(7, l1);
    ll.pushBack(4, l1);
    ll.pushBack(3, l1);
    ll.pushBack(5, l1);

    for(auto it: ll.nextLargerNodes(l1))
        cout << it << " ";
}