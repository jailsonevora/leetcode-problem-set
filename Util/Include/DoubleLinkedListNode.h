#include<iostream>

/**
 * Definition for double-linked list.
 * */
struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};