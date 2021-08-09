#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

class MyCircularQueue {
public:
    int head = 0, tail = 0;
    int queue[];
    MyCircularQueue(int k) {
        queue[k];
    }
    
    bool enQueue(int value) {
        queue[tail] = value;
        tail++;
    }
    
    bool deQueue() {
        
    }
    
    int Front() {
        return queue[head];
    }
    
    int Rear() {
        return queue[tail];
    }
    
    bool isEmpty() {
        if(tail == head)
            return true;
    }
    
    bool isFull() {
        if(tail != head)
            return true;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */