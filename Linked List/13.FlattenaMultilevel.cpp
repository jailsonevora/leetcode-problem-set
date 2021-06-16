#include<iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node* child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        
    }
};

int main(){

    Solution l1;
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);
    l1.pushBack(9);

    l1.flatten(l1.head);
}