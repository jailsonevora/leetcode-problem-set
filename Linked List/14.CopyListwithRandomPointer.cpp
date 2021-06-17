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