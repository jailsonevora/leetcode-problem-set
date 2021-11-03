#include<iostream>
#include<vector>
#include "Util\Include\BuildLinkedList.h"

using namespace std;


int main(){
    
    ListNode* l1 = nullptr;

    Solution ll;
    BuildLinkedList bl;
    bl.pushBack(1, l1);
    bl.pushBack(2, l1);
    bl.pushBack(3, l1);
    bl.pushBack(4, l1);
    bl.pushBack(5, l1);

    ll.swapNodes(l1,2);

    //[0,3,2,1,4,5] 3, 4, [1000000,1000001,1000002]
}