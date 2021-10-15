#include<iostream>

using namespace std;

/**
 * Definition for double-linked list.
 * */
struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};

/**
 * Definition for double-linked list.
 * */
struct NodeChild {
    int val;
    NodeChild *prev;
    NodeChild *next;
    NodeChild* child;
    NodeChild(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

/**
 * Definition for double-linked list.
 * */
class NodeRand {
public:
    int val;
    NodeRand* next;
    NodeRand* random;
    
    NodeRand(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};