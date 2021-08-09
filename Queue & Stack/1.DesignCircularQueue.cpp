#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

class MyCircularQueue {
public:
    int head = -1, tail = -1, size;
    int* queue;
    MyCircularQueue(int k) {
        queue = new int[k];
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
            head = 0;
        tail = (tail + 1) % size;
        queue[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if(!isEmpty())
            return queue[head];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return queue[tail];
        return -1;
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        return ((tail+1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 *  */
int main(){
    int value = 2, k = 10;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(value);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
}
