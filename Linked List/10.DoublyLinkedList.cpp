#include<iostream>

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};

class MyLinkedList {
public:
    
    int length;
    Node *head;
    /** Initialize your data structure here. */
    MyLinkedList() {        
        length = 0;
        head = NULL;        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index < length && index >= 0){       
            Node *cur = head;
            for (;index > 0; index--)
                cur = cur->next;
            return cur->val;            
        }        
        else return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        Node *cur = new Node(val);
        
        if(head)
            head->prev = cur;

        cur->next = head;
        head = cur;
        length++;        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        Node *temp = new Node(val);        
        length++;
        
        if(head){
            Node *cur = head;

            while (cur->next)
                cur = cur->next;
            
            cur->next = temp;
            temp->prev = cur;
        }
        else
            head = temp;        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if(index >= 0 && index <= length){

            if(index==0)
            {
                addAtHead(val);
                return;
            }

            Node *dmy = new Node(-1);
            dmy->next = head; 
            head->prev = dmy;  
            Node *cur = dmy;

            while(index-- > 0)
                cur = cur->next;

            Node *newnode = new Node(val);

            newnode->next = cur->next;
            newnode->prev = cur;
            
            if(cur->next){
                cur->next->prev = newnode;
                cur->next = newnode;
            }
            else{
                addAtTail(val);
                return;
            }            

            head = dmy->next;
            length++;
        }
        else
            return;        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if(index >= 0 && index < length){

            if(index==0)
            {
                head=head->next;
                length--;
                return;
            }

            Node *dmy = new Node(-1);
            dmy->next = head; 
            head->prev = dmy;         
            Node *cur = dmy;
                
            while(index-- > 0)
                cur = cur->next;

            if (cur->next){
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }

            head = dmy->next;
            length--;
        }
        else
            return;
    }
};

int main(){
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
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(7);
    // obj->addAtHead(2);
    // obj->addAtHead(1);

    // obj->addAtIndex(3,0);
    // obj->deleteAtIndex(2);

    // obj->addAtHead(6);
    // obj->addAtTail(4);

    // int param_1 = obj->get(4);

    // obj->addAtHead(4);
    // obj->addAtIndex(5,0);
    // obj->addAtHead(6);

    //test 13
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(5);
    obj->addAtIndex(1,2);
    int param_1 = obj->get(1);
    obj->addAtHead(6);
    obj->addAtTail(2);    
    param_1 = obj->get(3);    
    obj->addAtTail(1);  
    param_1 = obj->get(5);
    obj->addAtHead(2);
    param_1 = obj->get(2);
    obj->addAtHead(6);    
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */