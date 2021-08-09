#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        if(target == "0000")
            return 0;
        
        queue<int> queue;
        queue.push(0);

        bool seen[10000]{false};
        for(auto& d : deadends)
            seen[stoi(d)] = true;

        int targt = stoi(target);
        if(seen[0])
            return -1;

        //BFS
        for (int turns = 1; queue.size(); turns++)
        {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++)
            {
                int curr = queue.front();
                queue.pop();
                for (int j = 1; j < 10000; j *= 10)
                {
                    int mask = curr % (j * 10) / j,
                        masked = curr - (mask * j);
                    for (int k = 1; k < 10; k += 8)
                    {
                        int next = masked + (mask + k) % 10 * j;
                        if(seen[next])
                            continue;
                        if(next == targt)
                            return turns;
                        seen[next] = true;
                        queue.push(next);
                    }
                    
                }
                
            }
            
        }
        return -1;
    }
};