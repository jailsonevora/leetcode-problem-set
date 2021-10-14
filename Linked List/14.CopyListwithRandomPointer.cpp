#include<iostream>
#include<map>
#include "Util\Include\DoubleLinkedListNode.h"

using namespace std;

class Solution {
public:

    NodeRand *head = nullptr;

    NodeRand* copyRandomList(NodeRand* head) {

        NodeRand* curr = head;
        std::map<NodeRand*, NodeRand*> oldToCopy;

        while (curr)
        {   
            NodeRand* cpy = new NodeRand(curr->val);
            oldToCopy[curr] = cpy;
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {   
            NodeRand* cpy = oldToCopy[curr];
            cpy->next = oldToCopy[curr->next];
            cpy->random = oldToCopy[curr->random];
            curr = curr->next;
        }
        
        return oldToCopy[head];
    }

    void pushBack(int data, NodeRand *&head)
    {
        NodeRand* temp = new NodeRand(data);              

        NodeRand* curr = head;

        if (!head){  
            head = temp;
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
    }

    void random(int index, int indexRandom)
    {
        NodeRand* curr = head;       
        
        while (index-- > 1)
            curr = curr->next;

        NodeRand* tempCurr = head;
        if (indexRandom == -1){            
            curr->random = nullptr;
            return;
        }          
        while (indexRandom-- > 1)
            tempCurr = tempCurr->next;    
        curr->random = tempCurr;
    }
};

int main(){

    Solution l1;

    l1.pushBack(7,l1.head);
    l1.pushBack(13,l1.head);
    l1.pushBack(11,l1.head);
    l1.pushBack(10,l1.head);
    l1.pushBack(1,l1.head);

    // fill ramdom pointer
    l1.random(1, -1);
    l1.random(2, 1);
    l1.random(3, 5);
    l1.random(4, 3);
    l1.random(5, 1);

    l1.copyRandomList(l1.head);
}