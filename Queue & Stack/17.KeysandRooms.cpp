#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    //DFS with stack
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        bool seen[rooms.size()];
        seen[0] = true;

        stack<int> stk;
        stk.push(0);

        while (!stk.empty())
        {
            auto& keys = rooms[stk.top()];
            stk.pop();

            for (int newKey :keys)
                if(!seen[newKey])
                    seen[newKey] = true, 
                        stk.push(newKey);
        }

        for (bool visited : seen)
            if(!visited)
                return false;

        return true;
    }
};
