#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    // with queue and stack
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        stack<int> stack;
        queue<int> queue;

        for(auto s: sandwiches)
            stack.push(s);

        for(auto q: sandwiches)
            queue.push(q);

        while (!stack.empty())
        {
            if(queue.front() == stack.top()){
                queue.pop();
                stack.pop();
            }
            else{
                queue.push(queue.front());
                queue.pop();
            }
        }
        return queue.size();        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> students {1,1,1,0,0,1}, sandwiches {1,0,0,0,1,1};

    Solution sl;

    cout << sl.countStudents(students, sandwiches);

}