#include<iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
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

        if(index < 0 && index > length)
            return -1;
        else{
            Node *cur = head;
            for (;index > 0; index--)
                cur = cur->next;
            return cur->val;            
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        Node *cur = new Node(val);
        cur->next = head;
        head = cur;
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        Node *temp = new Node(val);
        
        if(head != NULL){
            Node *cur = head;

            while (cur->next != NULL)
                cur = cur->next;
            
            cur->next = temp;
            length++;
        }
        else
            head = temp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if(index > length) return;
        if(index < 0){
            addAtHead(val);
            length++;
        }
        else{
            Node *temp = new Node(val);

            Node *cur = head;

            while(index-1 > 0){
                cur = cur->next;
                index--;
            }
            temp->next = cur->next;
            cur->next = temp;
            length++;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        Node *temp = new Node(0);
        temp->next = head;
        Node *cur = head;

        if(index >= 0 && index < length){

            if(index == 0){
                head = cur->next;
                cur->next = NULL;                
                length--;
            }
            else{
                
                while(index-1 > 0){
                    cur = cur->next;
                    index--;
                }

                cur->next = cur->next->next;
                head = temp->next;
                length--;
            }
        }
    }
};

int main(){

    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * 
     */
    cin.sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    int val, index;
    cin >> val >> index;

    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index,val);
    int param_1 = obj->get(index);
    obj->deleteAtIndex(index);


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