#include<iostream>
#include<string>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for singly-linked list.    
struct ListNodeString {
    string val;
    ListNodeString *next;
    ListNodeString *prev;
    ListNodeString() : val(0), next(nullptr), prev(nullptr) {}
    ListNodeString(string x) : val(x), next(nullptr), prev(nullptr) {}
    ListNodeString(string x, ListNodeString *next, ListNodeString *prev) : val(x), next(next), prev(prev) {}
};