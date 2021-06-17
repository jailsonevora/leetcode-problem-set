#include<iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

using namespace std;

struct Node {
    int val;
    Node *next;
    Node* random;
    Node(int x) : val(x), random(nullptr), next(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    }
};

int main(){

    Solution l1;

    l1.pushBack(1, nullptr);
    l1.pushBack(2, nullptr);
    l1.pushBack(3, l2.head);
    l1.pushBack(4, nullptr);
    l1.pushBack(5, nullptr);
    l1.pushBack(6, nullptr);

    l1.flatten(l1.head);
}