#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


int main()
{
    //edge as adjMatrix
    vector<vector<int>> prerequisites = { 
        {1,0}
    };

    vector<vector<int>> queries = { 
        {1,0}
    };
    int numCourses = 4, k = 2;
    
    Solution sl;
    cout << sl.networkDelayTime(times, n, k);
}