#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if (mins.empty()) mins.push(val);
        else
            if (val <= mins.top()) mins.push(val);
    }
    
    void pop() {
        if (mins.top() == nums.top()) mins.pop();
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
    
    stack<int> nums;
    stack<int> mins;
};

class MinStack {
    vector<int> data;
    int min[10000];
    int minPtr;
public:
    /** initialize your data structure here. */
    MinStack() {
        minPtr = -1;
    }
    
    void push(int val) {
        data.push_back(val);
        if(minPtr >= 0){
            if(min[minPtr] > val)
                min[++minPtr] = val;
            else{
                min[minPtr+1] = min[minPtr];
                minPtr += 1;
            }
        }
        else{
            min[++minPtr] = val;
        }
    }
    
    void pop() {
        data.pop_back();
        minPtr -=1;
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min[minPtr];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * */
int main(){
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(3);
    obj->pop();
    obj->push(4);
    obj->push(-1);
    cout << obj->top();
    obj->push(6);
    cout << obj->getMin();
    obj->pop();
    cout << obj->getMin();
}