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
    cin.sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
}