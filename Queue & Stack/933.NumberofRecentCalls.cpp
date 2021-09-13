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
    sl.ping(1);     // requests = [1], range is [-2999,1], return 1
    sl.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
    sl.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
    sl.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], 
}