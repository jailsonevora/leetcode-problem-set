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

nt main(){
    cin.sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    // test 1
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(1);
    // obj->addAtTail(3);

    // obj->addAtIndex(1,2);
    // int param_1 = obj->get(1);
    
    // obj->deleteAtIndex(1);
    // param_1 = obj->get(1);

    //test 2
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);

    obj->addAtIndex(3,0);
    obj->deleteAtIndex(3);

    obj->addAtHead(6);
    obj->addAtTail(4);

    int param_1 = obj->get(4);

    obj->addAtHead(4);
    obj->addAtIndex(5,0);
    obj->addAtHead(6);

    //test 13
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(5);
    // obj->addAtIndex(1,2);
    // int param_1 = obj->get(1);
    // obj->addAtHead(6);
    // obj->addAtTail(2);    
    // param_1 = obj->get(3);    
    // obj->addAtTail(1);  
    // param_1 = obj->get(5);
    // obj->addAtHead(2);
    // param_1 = obj->get(2);
    // obj->addAtHead(6);    
}