#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
    vector<int> data;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        if(val < data.back())
            data.push_back(val);
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        data.back();
    }
    
    int getMin() {
        data.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * */
int main(){
    int val = -2;
    MinStack* obj = new MinStack();
    obj->push(val);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}