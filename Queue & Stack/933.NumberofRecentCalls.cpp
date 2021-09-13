#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
    queue<int> queue;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        queue.push(t);

        while(queue.front() < t - 3000)
            queue.pop();

        return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    RecentCounter sl;
}