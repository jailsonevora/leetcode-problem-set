#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
    vector<int> data;
    vector<int> min;
    int down = -1;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        data.push_back(val);
        if(down >= 0){
            if(min[down] > val)
                min[++down] = val;
            else{
                min[down+1] = min[down];
                down += 1;
            }
        }
        else
            min[++down] = val;
    }
    
    void pop() {
        data.pop_back();
        down -=1;
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min[down];
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