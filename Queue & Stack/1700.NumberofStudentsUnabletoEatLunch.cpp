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

        for(int s = sandwiches.size() - 1; s >= 0; s--)
            stack.push(sandwiches[s]);

        for(auto q: students)
            queue.push(q);

        int count = 0;

        while (!stack.empty())
        {
            if(queue.front() == stack.top()){
                queue.pop();
                stack.pop();
                count = 0;
            }
            else{
                queue.push(queue.front());
                queue.pop();
                count++;
            }

            if(count == queue.size())
                break;
        }
        return queue.size();        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    //vector<int> students {1,1,1,0,0,1}, sandwiches {1,0,0,0,1,1};
    vector<int> students {1,1,1,0,0,1}, sandwiches {1,0,0,0,1,1};

    Solution sl;

    cout << sl.countStudents(students, sandwiches);

}