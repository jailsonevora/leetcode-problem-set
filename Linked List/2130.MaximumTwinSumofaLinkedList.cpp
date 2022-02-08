#include<iostream>
#include<algorithm>
#include<vector>
#include"Util\Include\BuildLinkedList.h"

using namespace std;

class olution{
    public:

};

int main(){

    Solution sl;
    ListNode* head = nullptr;

    BuildLinkedList bl;

    vector<int> data = {2,1,3,5,6,4,7};
    for(auto it: data)
        bl.pushBack(it, head);

    sl.oddEvenList(head);
}